#pragma once

#include <string>

class Student;
class hashTable;

class doublyLinkedList {
public:
    struct node {
        hashTable* table;
        Student* student;
        node* next;
        node* prev;
        std::string key;

        node(hashTable* table, std::string key) {
            this->table = table;
            this->student = nullptr;
            this->next = nullptr;
            this->prev = nullptr;
            this->key = key;
        }
    };

private:
    node* head = nullptr;
    node* tail = nullptr;
    int linked_List_Size = 0;

public:
    void push_back(hashTable* table, std::string key);
    void push_front(hashTable* table, std::string key);

    void pop_back();
    void pop_front();

    int get_Size();
    node* give_Tail();
    node* give_Head();
    node* search(std::string key);

    ~doublyLinkedList();
};