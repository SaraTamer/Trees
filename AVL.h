
#ifndef TREES_AVL_H
#define TREES_AVL_H

#include <iostream>
#include "Student.h"
#include<map>
using namespace std;

template<class T>
class AVL {

public:
	Node<T>* root;
	AVL();
	Node<T>* createNode(student s);
	Node<T>* rotateleft(Node<T>* root);
	Node<T>* rotateright(Node<T>* root);
	int height(Node<T>* root);
	Node<T>* add_student(Node<T>* root, student s);
	Node<T>* delete_student(Node<T>* root, student s);
	Node<T>* findmin(Node<T>* root);
	bool search_student(Node<T>* root, int id);
	void insert();
	void delete_std(int id);
	void search(int id);
	void printReq(Node<T>* cur);
	void printInOrder();
	bool validData(string& n, string& dep, int& id, double& gpa);
	Node<T>* balanceBST(Node<T>* root);
	int start();
	map<string, int> depMap;

};

#endif //TREES_AVL_H
