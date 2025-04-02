//
// Created by Pablo Ruiz on 4/1/25.
//

#ifndef CMAKESFMLPROJECT_BST_H
#define CMAKESFMLPROJECT_BST_H
#include "Node.h"

template <typename T>
void InOrder(Node<T>* node, T f =[](T item){cout << "(" << item << ")" ;}){
    if(node == nullptr){return;}
    else{
        InOrder(node->_left);
        InOrder(node->_right);
    }
}

#endif //CMAKESFMLPROJECT_BST_H
