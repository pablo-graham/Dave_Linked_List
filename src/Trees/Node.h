//
// Created by Pablo Ruiz on 4/1/25.
//

#ifndef CMAKESFMLPROJECT_NODE_H
#define CMAKESFMLPROJECT_NODE_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
struct Node{
public:
    Node(const T& item= T(), Node<T>* left = nullptr, Node<T>* right = nullptr):_item(item), _left(left), _right(right){
    }

    friend ostream& operator <<(ostream& outs, const Node<T> n){
        outs<<"["<< n._item <<"]-> ";
        return outs;
    }


    T _item;
    Node<T> *_left;
    Node<T> *_right;
};

#endif //CMAKESFMLPROJECT_NODE_H
