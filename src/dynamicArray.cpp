/*
Alden Note: Thêm throw exception vào getter, setter
*/

#include <dynamicArray.h>
#include <iostream>

using namespace std;

template <typename T>
void dynamicArray<T>::set(int idx ,T val){
    if(idx < 0 || idx > sizeArr){
        return;
    }

    array[idx] = val;
}

template <typename T>
void get(int idx){
    if(idx < 0 || idx > sizeArr){
        return;
    }

    cout << array[idx];
}

template <typename T>
void dynamicArray<T>::push_Back(T val){
    if(sizeArr == capacity){
        resize();
    }

    array[i] = val;
    size++;
}

template <typename T>
void dynamicArray<T>::pop_Back(){
    if(sizeArr == 0){
        return;
    }

    size--;
}

template <typename T>
void dynamicArray<T>::resize(){
    capacity = capacity*2;
    T* newArray = new T[capacity];

    for(int i = 0; i < sizeArr; i++){
        newArray[i] = array[i];
    }

    array = newArray;
}

template <typename T>
int size(){
    return sizeArr;
}