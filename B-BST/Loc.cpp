#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// Hàm đệ quy hỗ trợ
void getTopKUtil(Node* node, int K, vector<Student>& result) {
    if (node == nullptr || result.size() >= K)
        return;

    // Vì cây sắp xếp GPA giảm dần, nên duyệt Left -> Root -> Right
    // sẽ ra từ cao xuống thấp
    getTopKUtil(node->left, K, result);

    if (result.size() < K) {
        result.push_back(node->data);
    }

    getTopKUtil(node->right, K, result);
}

// Hàm chính: Lấy Top K
vector<Student> getTopK(Node* root, int K) {
    vector<Student> result;
    getTopKUtil(root, K, result);
    return result;
}



// Hàm đệ quy hỗ trợ
void getTopKUtil(Node* node, int K, vector<Student>& result) {
    if (node == nullptr || result.size() >= K)
        return;

    // Vì cây sắp xếp GPA giảm dần, nên duyệt Left -> Root -> Right
    // sẽ ra từ cao xuống thấp
    getTopKUtil(node->left, K, result);

    if (result.size() < K) {
        result.push_back(node->data);
    }

    getTopKUtil(node->right, K, result);
}

// Hàm chính: Lấy Top K
vector<Student> getTopK(Node* root, int K) {
    vector<Student> result;
    getTopKUtil(root, K, result);
    return result;
}