//
// Created by Pablo Ruiz on 3/18/25.
//

#ifndef CMAKESFMLPROJECT_NODE_H
#define CMAKESFMLPROJECT_NODE_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
struct Node{
public:
    Node(const T& item= T(), Node<T>* next = nullptr):_item(item), _next(next){
    }

    friend ostream& operator <<(ostream& outs, const Node<T> n){
        outs<<"["<< n._item <<"]-> ";
        return outs;
    }


    T _item;
    Node<T> *_next;
    Node<T> *_prev;
};

#endif //CMAKESFMLPROJECT_NODE_H
