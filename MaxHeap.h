
#ifndef TREES_MAXHEAP_H
#define TREES_MAXHEAP_H

#include <iostream>
#include <vector>
#include "student.h"
#include <fstream>
#include "MinHeap.h"

using namespace std;

class MaxHeap: public MinHeap{
private:
    vector<student> myVec;
    void heapify(vector<student> &vec, int size, int parent) override;
    int parent(int i){ return (i-1) / 2;}
    int left(int i){ return i * 2 + 1;}
    int right(int i){ return i * 2 + 2;}
public:
    MaxHeap(){};
};




#endif //TREES_MAXHEAP_H
