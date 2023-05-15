#include"BST.h"
#include "MaxHeap.h"
#include "AVL.h"
#include "AVL.cpp"
#include "BST.cpp"
#include "MinHeap.cpp"
#include "MaxHeap.cpp"

using namespace std;
void LoadData(BST& bst, AVL& avl, MinHeap& minh, MaxHeap& maxh);
int main()
{
    BST bst;
    AVL avl;
    MinHeap minHeap;
    MaxHeap maxHeap;
    LoadData(bst, avl, minHeap, maxHeap);

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
                cont = avl.start();
                break;
            }
            else if(choice == 3)
            {
                minHeap.start();
            }
            else if(choice == 4)
            {
                maxHeap.start();
            }
             else if (choice == 5) {
                return;
            }
        } while (cont);
    } while (choice);

    return 0;
}
void LoadData(BST& bst, AVL& avl, MinHeap& minh, MaxHeap& maxh) {
    fstream file;
    file.open("Students.txt", ios::in);
    if (file.fail())
    {
        file.close();
        file.open("Students.txt", ios::out);
        file.close();
    }
    else {
        int nStudents;
        file >> nStudents;
        for(int i=nStudents;i>0;i--) {
            string name, department,temp;
            int id;
            double GPA;
            file >> id;
            file >> temp;
            getline(file, name);
            file >> GPA;
            file >> department;
            temp += name;

            student s (temp, department, id, GPA);
            bst.insert(s);
            avl.insertStudent(s);
            minh.insert(s);
            maxh.insert(s);
            //call insert that takes student 
        }
    }
}

