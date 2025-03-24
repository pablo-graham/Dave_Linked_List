//
// Created by Pablo Ruiz on 3/18/25.
//
#ifndef PABLO_LIST_CPP
#define PABLO_LIST_CPP
#include "List.h"

template<typename T>
void List<T>::push_front(Node<T> *node)
{
    node->_next = head;
    head->_prev = node;
    head = node;
    _size++;
}
template<typename T>
void List<T>::push_back(Node<T>* node){
    tail->_next = node;
    tail = node;
    _size++;
}
template<typename T>
void List<T>::push_front(const T &data)
{
    if(empty())
        add_first_node(data);
    else
    {
        push_front(create_node(data));
    }
}

template<typename T>
void List<T>::push_back(const T &data) {
    if(this->empty()){
        add_first_node(data);
    }else{
        push_back(create_node(data));
    }
}

template<typename T>
Node<T> * List<T>::create_node(const T &data)
{
    return new Node(data);
}

template<typename T>
void List<T>::add_first_node(const T& data){
    if(!this->empty()){
        push_front(data);
    }else{
        head = create_node(data);
        tail = head;
    }
    _size++;
}

template<typename T>
bool List<T>::empty() const
{
    return head == nullptr;
}

template <typename T>
int List<T>::size() const{
    return _size;
}// return the number of nodes in the list

template <typename T>
void List<T>::pop_back(){
    Node<T>* temp = tail->_prev;
    tail = temp;
    delete[] temp;
    _size--;
} // remove tail node

template <typename T>
void List<T>::pop_font(){
    Node<T>* temp = head;
    head = head->_next;
    delete[] temp;
    _size--;
} // remove head node

template <typename T>
T& List<T>::front(){
    return head->_item;
} // return data on the head node

template <typename T>
T& List<T>::back(){
    return tail->_item;
}

template  <typename T>
bool List<T>::isInList(T item){

    Node<T>* walker = head;

    while(walker != nullptr){
        if(walker->_item == item){
            return true;
        }
    }
    return false;
}

template  <typename T>
void List<T>::clearList(){
    Node<T>* walker = head;
    while(walker != nullptr){
        head = head->_next;
        delete[] walker;
        walker = head;
    }
    _size = 0;
}

template  <typename T>
void List<T>::printList() {
    Node<T>*walker = head;
    while(walker !=  nullptr){
        cout << *walker;
        walker = walker->_next;
    }
    cout << "[|||]\n";
}

template  <typename T>
Node<T>* List<T>::find(T item){
    Node<T>* walker = head;
    while(walker != nullptr){
        if(*walker == item){
            return walker;
        }
    }
    cout << item << " is not in list\n";
    return nullptr;
}

template <typename T>
void List<T>::insertBefore(Node<T>* beforeThis, T item){
    if(beforeThis == head){
        push_front(item);
    }else{
        Node<T>* temp = create_node(item);
        temp->_next = beforeThis;
        temp->_prev = beforeThis->_prev;
        beforeThis->_prev->_next = temp;
        beforeThis->_prev = temp;
    }
}

template <typename T>
void List<T>::insertAfter(Node<T>* afterThis, T item){

}

#endif