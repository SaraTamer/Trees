
#ifndef TREES_MINHEAP_H
#define TREES_MINHEAP_H

#include <iostream>
#include "student.h"
#include <vector>
#include <fstream>


using namespace std;


template<class T>
class MinHeap{
protected:
    vector<T> myVec;
public:
    MinHeap(){};

    virtual void heapify(vector<T> vec, int size, int parent);
    void buildHeap(vector<T> vec, int size);
    void heapSort(vector<T> vec, int size);
    int parent(int i){ return (i-1) / 2;}
    int left(int i){ return i * 2 + 1;}
    int right(int i){ return i * 2 + 2;}
    void print();
    void loadVec();
    void insert(T item);
    void studentMenu();
};

#endif //TREES_MINHEAP_H
