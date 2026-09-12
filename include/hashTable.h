#pragma once

#include "Student.h"
#include "doublyLinkedList.h"
#include "dynamicArray.h"

class hashTable{
    private:
        int segment_Length;
        dynamicArray<doublyLinkedList> bucket;
        int capacity;
        int size;

        int hash_Func(string key);
    protected:
        
    public:
        hashTable(int capacity, int segment_Length);

        ~hashTable();

        Student get(string key);

        void add(Student new_Student, string key);
};