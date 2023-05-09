
#ifndef TREES_MAXHEAP_H
#define TREES_MAXHEAP_H

#include <iostream>
#include <vector>
#include "HeapStudent.h"
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



template<class T>
void MaxHeap<T>::heapify(vector<T> vec, int size, int parent)
{
    int l = left(parent);
    int r = right(parent);
    int maximum = parent;
    if(l < size && vec[maximum] < vec[l])
        maximum = l;
    if(r < size && vec[maximum] < vec[r])
        maximum = r;
    if(maximum != parent)
    {
        swap(vec[maximum] , vec[parent]);
        heapify(vec, size,maximum);
    }
}

#endif //TREES_MAXHEAP_H
