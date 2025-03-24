//
// Created by Pablo Ruiz on 3/19/25.
//

#ifndef CMAKESFMLPROJECT_ITERATOR_H
#define CMAKESFMLPROJECT_ITERATOR_H

#include "../Node/Node.h"
#include <iterator>
template<typename T>
class Iterator {
    Node<T>* _current;

public:
    Iterator(Node<T>* current);

    ///bidirection iterator

    Iterator& operator++(); //prefix
    Iterator operator++(int); // postfix
    Iterator& operator--(); //prefix
    Iterator operator--(int); // postfix

    T& operator*(); // deferfence
    T* operator->();
    friend bool operator==(const Iterator &left, const Iterator &right);
    friend bool operator!=(const Iterator& left, const Iterator& right);
};

#include "Iterator.h"
#endif //CMAKESFMLPROJECT_ITERATOR_H
