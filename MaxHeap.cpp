#include "MaxHeap.h"

void MaxHeap::heapify(vector<student> &vec, int size, int parent)
{
    int l = left(parent);
    int r = right(parent);
    int maximum = parent;
    if(l < size && vec[maximum].getGPA() < vec[l].getGPA())
        maximum = l;
    if(r < size && vec[maximum].getGPA() < vec[r].getGPA())
        maximum = r;
    if(maximum != parent)
    {
        swap( vec[maximum], vec[parent]);
        heapify(vec, size,maximum);
    }
}
