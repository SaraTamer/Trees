#include"BST.h"
#include "MaxHeap.h"
#include "AVL.h"
#include "AVL.cpp"
#include "BST.cpp"
#include "MinHeap.cpp"
#include "MaxHeap.cpp"

using namespace std;

int main()
{
    BSTStudent bst;
    AVL avl;
    MinHeap<student> minHeap;
    MaxHeap<student> maxHeap;

    int choice;
    do
    {
        cout << "Choose Data Structure:\n1. BST\n2. AVL\n3. Min Heap\n4. Max Heap\n5. Exit Program\n";
        cin >> choice;
        int cont = 1;
        do
        {
            if (choice == 1) {
                cont = bst.start();
                break;
            }
            else if(choice == 2)
            {
//                cont = avl.start();
                break;
            }
            else if(choice == 3)
            {
                minHeap.studentMenu();
            }
            else if(choice == 4)
            {
                maxHeap.studentMenu();
            }
        } while (cont);
    } while (choice);

    return 0;
}


