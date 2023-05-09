
#ifndef TREES_MAXHEAP_H
#define TREES_MAXHEAP_H

#include <iostream>
#include <vector>
#include "student.h"
#include <fstream>
#include "MinHeap.h"

using namespace std;

template<class T>
class MaxHeap: public MinHeap<T>{
private:
    vector<T> myVec;
public:
    MaxHeap(){};
    void heapify(vector<T> vec, int size, int parent) override;
    int parent(int i){ return (i-1) / 2;}
    int left(int i){ return i * 2 + 1;}
    int right(int i){ return i * 2 + 2;}
};




#endif //TREES_MAXHEAP_H
