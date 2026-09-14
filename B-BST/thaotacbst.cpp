#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// ====================== CÁC HÀM HỖ TRỢ ======================
int height(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

void updateHeight(Node* node) {
    if (node)
        node->height = 1 + max(height(node->left), height(node->right));
}

// ====================== XOAY CÂY ======================

// Xoay phải (Right Rotation) - LL
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Xoay trái (Left Rotation) - RR
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// ====================== CÂN BẰNG NODE ======================
Node* balanceNode(Node* node) {
    if (!node) return nullptr;

    updateHeight(node);
    int balance = getBalance(node);

    // Left-Left
    if (balance > 1 && getBalance(node->left) >= 0)
        return rotateRight(node);

    // Right-Right
    if (balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);

    // Left-Right
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right-Left
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// ====================== INSERT ======================
Node* insert(Node* node, Student s) {
    // 1. Thêm như BST bình thường
    if (!node) return new Node(s);

    if (s < node->data) {
        node->left = insert(node->left, s);
    }
    else if (node->data < s) {
        node->right = insert(node->right, s);
    }
    else {
        // Trùng key (thường không xảy ra vì có mssv)
        return node;
    }

    // 2. Cân bằng lại
    return balanceNode(node);
}

// Tìm node có giá trị nhỏ nhất bên phải (dùng khi xóa node có 2 con)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// ====================== REMOVE ======================
Node* remove(Node* node, Student s) {
    // 1. Xóa như BST bình thường
    if (node == nullptr)
        return node;

    if (s < node->data) {
        node->left = remove(node->left, s);
    }
    else if (node->data < s) {
        node->right = remove(node->right, s);
    }
    else {
        // Đã tìm thấy node cần xóa

        // Trường hợp 1: Node chỉ có 1 con hoặc không có con
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = node->left ? node->left : node->right;

            // Không có con
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            // Có 1 con
            else {
                *node = *temp;          // copy nội dung con lên
            }
            delete temp;
        }
        // Trường hợp 2: Node có 2 con
        else {
            // Tìm node nhỏ nhất bên cây con phải
            Node* temp = minValueNode(node->right);

            // Copy dữ liệu của node đó lên
            node->data = temp->data;

            // Xóa node nhỏ nhất bên phải
            node->right = remove(node->right, temp->data);
        }
    }

    // Nếu cây chỉ còn 1 node và đã xóa thì trả về nullptr
    if (node == nullptr)
        return node;

    // 2. Cân bằng lại cây
    return balanceNode(node);
}