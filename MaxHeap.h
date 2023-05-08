
#ifndef TREES_MAXHEAP_H
#define TREES_MAXHEAP_H

#include <iostream>

#include "Student.h"

using namespace std;
template<class T>
struct Node {
    T value;
    Node* left, * right;

    Node(T val) {
        value = val;
        left = right = nullptr;
    }
};

template<class T>
class MaxHeap{
private:
    Node<T>* root;
};
#endif //TREES_MAXHEAP_H
