
#ifndef TREES_MINHEAP_H
#define TREES_MINHEAP_H

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
class MinHeap{
private:
    Node<T>* root;
};
#endif //TREES_MINHEAP_H
