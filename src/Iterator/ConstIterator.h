//
// Created by Pablo Ruiz on 3/20/25.
//

#ifndef CMAKESFMLPROJECT_CONSTITERATOR_H
#define CMAKESFMLPROJECT_CONSTITERATOR_H

#include "../Node/Node.h"
#include <iterator>

template<typename T>
class ConstIterator {
    Node<T>* _current;

public:
    ConstIterator(Node<T>* current);

    ///bidirection iterator

    ConstIterator& operator++(); //prefix
    ConstIterator operator++(int); // postfix
    ConstIterator& operator--(); //prefix
    ConstIterator operator--(int); // postfix

    T operator*(); // deferfence
    T operator->();
    friend bool operator==(const ConstIterator &left, const ConstIterator &right);
    friend bool operator!=(const ConstIterator& left, const ConstIterator& right);
};

template<typename T>
ConstIterator<T>::ConstIterator(Node<T>* current){
    _current = current;
}

///bidirection iterator

template<typename T>
ConstIterator<T>& ConstIterator<T>::operator++(){
    _current = _current->_next;
    return *this;
} //prefix
template<typename T>
ConstIterator<T> ConstIterator<T>::operator++(int){
    ConstIterator<T> temp = &this;
    _current = _current->_next;
    return temp;

} // postfix
template<typename T>
ConstIterator<T>& ConstIterator<T>::operator--(){
    _current = _current->_prev;
    return *this;
} //prefix
template<typename T>
ConstIterator<T> ConstIterator<T>::operator--(int){
    ConstIterator<T> temp = &this;
    _current = _current->_prev;
    return temp;
} // postfix

template<typename T>
T ConstIterator<T>::operator*(){
    return _current->_item;
}

template<typename T>
T ConstIterator<T>::operator->(){
    return _current->_item;
}

template<typename T>
bool operator==(const ConstIterator<T> &left, const ConstIterator<T> &right){
    return left._current == right._current;
}

template<typename T>
bool operator!=(const ConstIterator<T>& left, const ConstIterator<T>& right){
    return left._current != right._current;
}
#endif //CMAKESFMLPROJECT_CONSTITERATOR_H
