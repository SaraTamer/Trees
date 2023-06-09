

#ifndef TREES_BST_H
#define TREES_BST_H

#include <iostream>
#include <regex>
#include "Student.h"

using namespace std;

class BST {
	Node* root = nullptr;
	Node* Search(int id);
public:
	int start();
	void AddStudent();
	void insert(student val);
	void RemoveStudent(int id);
	void SearchStudent(int id);
	void PrintAll();//sorted by ID
};



#endif //TREES_BST_H
