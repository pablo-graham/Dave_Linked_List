//
// Created by Pablo Ruiz on 3/19/25.
//

#ifndef PABLO_ITERATOR
#define PABLO_ITERATOR
#include "Iterator.h"

template<typename T>
Iterator<T>::Iterator(Node<T>* current){
    _current = current;
}

///bidirection iterator

template<typename T>
Iterator<T>& Iterator<T>::operator++(){
    _current = _current->_next;
    return *this;
} //prefix
template<typename T>
Iterator<T> Iterator<T>::operator++(int){
    Iterator<T> temp = &this;
    _current = _current->_next;
    return temp;

} // postfix
template<typename T>
Iterator<T>& Iterator<T>::operator--(){
    _current = _current->_prev;
    return *this;
} //prefix
template<typename T>
Iterator<T> Iterator<T>::operator--(int){
    Iterator<T> temp = &this;
    _current = _current->_prev;
    return temp;
} // postfix

template<typename T>
T& Iterator<T>::operator*(){
    return _current->_item;
}

template<typename T>
T* Iterator<T>::operator->(){
    return &(_current->_item);
}

template<typename T>
bool operator==(const Iterator<T> &left, const Iterator<T> &right){
    return left._current == right._current;
}

template<typename T>
bool operator!=(const Iterator<T>& left, const Iterator<T>& right){
    return left._current != right._current;
}
#endif