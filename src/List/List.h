#ifndef PABLO_LIST
#define PABLO_LIST

#include "../Node/Node.h"
#include <iostream>

template <typename T>
class List{
private:
    Node<T>* head = nullptr, *tail = nullptr;
    int _size = 0;

    void push_front(Node<T>* node);// adds data in a node previous to head
    void push_back(Node<T>* node);// adds data in a node previous to head
    Node<T>* create_node(const T& data);// creates a new node
    void add_first_node(const T& data);// adds the first node to the list

public:
    void push_front(const T& data); // adds data in a node previous to head
    void push_back(const T& data);
    bool empty() const;// return true if list is empty, otherwise false
    int size() const;// return the number of nodes in the list
    void pop_back(); // remove tail node
    void pop_font(); // remove head node
    T& front(); // return data on the head node
    T& back();// return data in the tail node
    bool isInList(T item);
    void clearList();
    void printList();
    Node<T>* find(T item);
    void insertBefore(Node<T>* beforeThis, T item);
    void insertAfter(Node<T>* afterThis, T item);

};

#include "List.cpp"
#endif