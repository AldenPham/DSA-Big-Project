#include "include/Student.h"
#include "include/hashTable.h"
#include "include/doublyLinkedList.h"
#include <iostream>
using namespace std;
/*
int main(){

    doublyLinkedList list;

    cout << "Initial size: "
         << list.get_Size() << endl;

    // Thêm node đầu tiên
    list.push_back(nullptr, "25");

    cout << "After push_back 25: "
         << list.get_Size() << endl;

    // Thêm node thứ hai
    list.push_back(nullptr, "13");

    cout << "After push_back 13: "
         << list.get_Size() << endl;

    // Tìm node
    doublyLinkedList::node* found = list.search("25");

    if (found != nullptr) {
        cout << "Found: " << found->key << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    // Tìm node không tồn tại
    found = list.search("99");

    if (found == nullptr) {
        cout << "99 does not exist" << endl;
    }

    // Xóa cuối
    list.pop_back();

    cout << "After pop_back: "
         << list.get_Size() << endl;

    // Xóa đầu
    list.pop_front();

    cout << "After pop_front: "
         << list.get_Size() << endl;

    return 0;

}
*/

/*
int main() {
    // Root table: segment length = 2
    hashTable root(100, 2);

    Student s1("Nguyen Van A", "25133074", 8, 1);
    Student s2("Tran Van B", "25133125", 7, 2);
    Student s3("Le Van C", "25133099", 9, 1);
    Student s4("Pham Van D", "26123001", 6, 3);

    root.add(s1, s1.get_MSSV());
    root.add(s2, s2.get_MSSV());
    root.add(s3, s3.get_MSSV());
    root.add(s4, s4.get_MSSV());

    cout << "Them 4 sinh vien thanh cong!" << endl;

    return 0;
}
*/