#include "../include/hashTable.h"
#include "../include/Student.h"
#include "../include/doublyLinkedList.h"
#include "../include/dynamicArray.h"
#include <sstream>

//Constructor
hashTable::hashTable(int capacity, int segment_Length) : bucket(capacity){
    this->capacity = capacity;
    this->segment_Length = segment_Length;
    this->size = 0;
};


//func
int hashTable::hash_Func(string key){
    string segment = key.substr(0, segment_Length);
    string remaining = key.substr(segment_Length);

    int idx = stoi(segment) % capacity;

    return idx;
}



//add
void hashTable::add(Student new_Student, string key){
    int hash = hash_Func(new_Student.get_MSSV());
    string segment = new_Student.get_MSSV().substr(0, segment_Length);
    string nextKey = key.substr(segment_Length);

    doublyLinkedList::node* curr = bucket[hash].search(segment);

           
        
    if(curr == nullptr){ 
        if(nextKey == ""){
            bucket[hash].push_back(nullptr, segment);

            curr = bucket[hash].give_Tail();

            curr->student = new Student(new_Student);
        }
        else{
            hashTable* child = new hashTable(1, 3);
            bucket[hash].push_back(child, segment);


            curr = bucket[hash].give_Tail();
            curr->table->add(new_Student, nextKey);
        }
        
    }
    else{
        if(nextKey == ""){
            curr->student = new Student(new_Student);
        }
        else{
            curr->table->add(new_Student, nextKey);
        }
          
    }
}

hashTable::~hashTable() {
    for (int i = 0; i < capacity; i++) {
        doublyLinkedList::node* curr = bucket[i].give_Head();

        while (curr != nullptr) {
            doublyLinkedList::node* next = curr->next;

            if (curr->table != nullptr) {
                delete curr->table;
            }

            if (curr->student != nullptr) {
                delete curr->student;
            }

            curr = next;
        }
    }
}
