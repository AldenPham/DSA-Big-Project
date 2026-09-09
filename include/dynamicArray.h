#pragma once

template <typename T>

class dynamicArray{
    private:
    T* array;
    int sizeArr;
    int capacity;

    public:
    dynamicArray(int capacity, T defaultValue = T()){;
        this->capacity = capacity;
        T* array = new T[capacity];

        for(int i = 0; i < capacity; i++){
            array[i] = defaultValue;
        }

        sizeArr = 0;
    }

    void push_Back(T val);

    void pop_Back();

    int size();

    void resize()
};