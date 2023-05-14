
#ifndef TREES_MINHEAP_H
#define TREES_MINHEAP_H

#include <iostream>
#include "student.h"
#include <vector>
#include <fstream>


using namespace std;


class MinHeap{
protected:
    vector<student>  myVec;
    virtual void heapify(vector<student>  vec, int size, int parent);
    void buildHeap(vector<student>  vec, int size);
    void heapSort(vector<student>  vec, int size);
    int parent(int i){ return (i-1) / 2;}
    int left(int i){ return i * 2 + 1;}
    int right(int i){ return i * 2 + 2;}
    void loadVec();
    void insert(student item);

public:
    MinHeap(){};
    void print();
    void studentMenu();
};

#endif //TREES_MINHEAP_H
