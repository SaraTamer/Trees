#include"BST.h"
#include "HeapStudent.h"
#include "MaxHeap.h"

using namespace std;

int main()
{
    BSTStudent bst;

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
         cont = bst.start();
                break;
            }
            else if(choice == 3)
            {
                MinHeap<HeapStudent> minHeap;
                minHeap.studentMenu();
            }
            else if(choice == 4)
            {
                MaxHeap<HeapStudent> maxHeap;
                maxHeap.studentMenu();
            }
        } while (cont);
    } while (choice);

    return 0;
}


