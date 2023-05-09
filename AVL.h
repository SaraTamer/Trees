
#ifndef TREES_AVL_H
#define TREES_AVL_H

#include <iostream>
#include "Student.h"
#include<map>
using namespace std;
template<class T>
struct node {
    T value;
    node* left, * right;

    node(T val) {
        value = val;
        left = right = nullptr;
    }
};
template<class T>
class AVL {

public:
	node<T>* root;
	AVL();
	node<T>* createnode(student s);
	node<T>* rotateleft(node<T>* root);
	node<T>* rotateright(node<T>* root);
	int height(node<T>* root);
	node<T>* add_student(node<T>* root, student s);
	node<T>* delete_student(node<T>* root, student s);
	node<T>* findmin(node<T>* root);
	bool search_student(node<T>* root, int id);
	void insert();
	void delete_std(int id);
	void search(int id);
	void printReq(node<T>* cur);
	void printInOrder();
	bool validData(string& n, string& dep, int& id, double& gpa);
	node<T>* balanceBST(node<T>* root);
	int start();
	map<string, int> depMap;

};

#endif //TREES_AVL_H
