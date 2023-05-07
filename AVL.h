
#ifndef TREES_AVL_H
#define TREES_AVL_H

#include <iostream>
#include "Student.h"
#include<iostream>
#include<map>
using namespace std;
class AVL {
public:
	node* root;
	AVL();
	node* createnode(student s);
	node* rotateleft(node* root);
	node* rotateright(node* root);
	int height(node* root);
	node* add_student(node* root, student s);
	node* delete_student(node* root, student s);
	node* findmin(node* root);
	bool search_student(node* root, int id);
	void insert();
	void delete_std(int id);
	void search(int id);
	void printReq(node* cur);
	void printInOrder();
	bool validData(string& n, string& dep, int& id, double& gpa);
	int start();
	map<string, int> depMap;

};

#endif //TREES_AVL_H
