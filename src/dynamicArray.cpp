#include <dynamicArray.h>

template <typename T>
void dynamicArray<T>::push_Back(T val){
    if(sizeArr == capacity){
        resize();
    }

    array[i] = val;
    size++;
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