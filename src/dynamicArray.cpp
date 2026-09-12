/*
Alden Note: Thêm throw exception vào getter, setter
*/

#include <dynamicArray.h>
#include <iostream>
#include <stdexcept>
using namespace std;

//Constructor
template <typename T>
dynamicArray<T>::dynamicArray(int capacity, T defaultValue){
        this->capacity = capacity;
        this->array = new T[capacity];

        for(int i = 0; i < capacity; i++){
            array[i] = defaultValue;
        }

        sizeArr = capacity;
}

//Func push_Back()
template <typename T>
void dynamicArray<T>::push_Back(T val){
    if(sizeArr == capacity){
        resize();
    }

    array[sizeArr] = val;
    sizeArr++;
}

//Func pop_back
template <typename T>
void dynamicArray<T>::pop_Back(){
    if(sizeArr == 0){
        throw out_of_range("Index out of range");
    }

    sizeArr--;
}

//Func Resize
template <typename T>
void dynamicArray<T>::resize(){
    capacity = capacity*2;

    T* newArray = new T[capacity];

    for(int i = 0; i < sizeArr; i++){
        newArray[i] = array[i];
    }

    delete[] array;    
    array = newArray;
}

//Func Size
template <typename T>
int dynamicArray<T>::size(){
    return sizeArr;
}

//Getter setter
template <typename T>
T& dynamicArray<T>::operator[](int idx) {

    if (idx < 0 || idx >= sizeArr) {
        throw std::out_of_range("Index out of range");
    }

    return array[idx];
}

//Destructor
template <typename T>
dynamicArray<T>::~dynamicArray(){
    delete[] array;
}