//
// Created by Pablo Ruiz on 3/20/25.
//

#ifndef CMAKESFMLPROJECT_REVERSEITERATOR_H
#define CMAKESFMLPROJECT_REVERSEITERATOR_H

#include "../Node/Node.h"
#include <iterator>

template<typename T>
class ReverseIterator {
    Node<T>* _current;

public:
    ReverseIterator(Node<T>* current);


    ReverseIterator& operator++(); //prefix
    ReverseIterator operator++(int); // postfix
    ReverseIterator& operator--(); //prefix
    ReverseIterator operator--(int); // postfix

    T& operator*(); // deferfence
    T* operator->();
    friend bool operator==(const ReverseIterator &left, const ReverseIterator &right);
    friend bool operator!=(const ReverseIterator& left, const ReverseIterator& right);
};

template<typename T>
ReverseIterator<T>::ReverseIterator(Node<T>* current){
    _current = current;
}

///bidirection iterator

template<typename T>
ReverseIterator<T>& ReverseIterator<T>::operator++(){
    _current = _current->_prev;
    return *this;
} //prefix
template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator++(int){
    ReverseIterator<T> temp = &this;
    _current = _current->_prev;
    return temp;

} // postfix
template<typename T>
ReverseIterator<T>& ReverseIterator<T>::operator--(){
    _current = _current->_next;
    return *this;
} //prefix
template<typename T>
ReverseIterator<T> ReverseIterator<T>::operator--(int){
    ReverseIterator<T> temp = &this;
    _current = _current->_next;
    return temp;
} // postfix

template<typename T>
T& ReverseIterator<T>::operator*(){
    return _current->_item;
}

template<typename T>
T* ReverseIterator<T>::operator->(){
    return &(_current->_item);
}

template<typename T>
bool operator==(const ReverseIterator<T> &left, const ReverseIterator<T> &right){
    return left._current == right._current;
}

template<typename T>
bool operator!=(const ReverseIterator<T>& left, const ReverseIterator<T>& right){
    return left._current != right._current;
}
#endif //CMAKESFMLPROJECT_REVERSEITERATOR_H
