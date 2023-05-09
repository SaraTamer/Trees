

#ifndef TREES_BST_H
#define TREES_BST_H

#include <iostream>
#include <string>
#include <regex>
#include "Student.h"


using namespace std;


template<class T>
class BST {
	Node<T>* root = nullptr;
public:
	void insert(T val);
	void printInOrder();
};

class BSTStudent {
	BST<student> students;
public:
	int start();
	void AddStudent();
	//void RemoveStudent();
	//void SearchStudent();
	void PrintAll();//sorted by ID
};






#endif //TREES_BST_H
