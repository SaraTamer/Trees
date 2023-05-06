#include"BST.h"

int main() {
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
            }

        } while (cont);
    } while (choice);

    return 0;
}