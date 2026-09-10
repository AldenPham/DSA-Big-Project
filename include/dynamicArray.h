/*
Template <typename T> = generic OOP

Vì mình muốn array có thể chứa được nhiều loại dữ liệu, 
nên dùng generic để nó tự điều chỉnh kiểu dữ liệu theo
lựa chọn của mình mà ko phải viết nhiều cái dynamicArray
 cho từng kiểu dữ liệu

Hướng dẫn sytax
-Tạo array: dynamicArray<"Loại dữ liệu, vd: int, string"> "tên array"("Size array", "thêm giá trị bạn đầu nếu muốn")
-Nhét phần tử vào cuối array: "tên array".push_back("dữ liệu"), lưu ý phải trùng với loại dữ liệu array đang lưu trữ

~dynamicArray destructor ( giai phong bo nho khi ma obj chet)
 */


#pragma once

template <typename T>

class dynamicArray{
    private:
    T* array;
    int sizeArr;
    int capacity;

    void resize();
    
    public:
    dynamicArray(int capacity, T defaultValue = T());
    ~dynamicArray();

    void push_Back(T val); //

    void pop_Back(); //

    int size(); 
    
    T& operator[](int idx);

};