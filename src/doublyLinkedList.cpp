#include "../include/doublyLinkedList.h"
#include <exception>
#include <string>

//push_back
void doublyLinkedList::push_back(hashTable* table, std::string key){
    node* curr = new node(table, key);
    
    if(head == nullptr){
        head = curr;
        tail = curr;
        linked_List_Size++; 
        return;
    }

    curr->prev = tail;
    tail->next = curr;
    tail = curr;
    linked_List_Size++;
}

//push_front
void doublyLinkedList::push_front(hashTable* table, std::string key){
    node* curr = new node(table, key);

    if(head == nullptr){
        head = curr;
        tail = curr;
        linked_List_Size++;
        return;
    }

    curr->next = head;
    head->prev = curr;
    head = curr;
    linked_List_Size++;
}

//pop_back
void doublyLinkedList::pop_back(){
    if(tail == nullptr){
        return;
    }
    else if(linked_List_Size == 1){
        delete tail;
        tail = nullptr;
        head = nullptr;
        linked_List_Size--;
        return;
    }

    node* curr = tail->prev;
    curr->next = nullptr;
    delete tail;
    tail = curr;
    linked_List_Size--;
}

//pop_front
void doublyLinkedList::pop_front(){
    if(head == nullptr){
        return;
    }
    else if(linked_List_Size == 1){
        delete head;
        tail = nullptr;
        head = nullptr;
        linked_List_Size--;
        return;
    }

    node* curr = head->next;
    curr->prev = nullptr;
    delete head;
    head = curr;
    linked_List_Size--;
}

//search
doublyLinkedList::node* doublyLinkedList::search(std::string key){
    if(linked_List_Size == 0){
        return nullptr;
    }

    node* curr = head;
    while(curr != nullptr){
        if(curr->key == key){ 
            return curr;
        }

        curr = curr->next;
    }

    return nullptr;
}

//give tail
doublyLinkedList::node* doublyLinkedList::give_Tail(){
    return tail;    
}

doublyLinkedList::node* doublyLinkedList::give_Head(){
    return head;    
}

//get size
int doublyLinkedList::get_Size(){
    return linked_List_Size;
}

//destructor
doublyLinkedList::~doublyLinkedList() {
    while (head != nullptr) {
        pop_front();
    }
}