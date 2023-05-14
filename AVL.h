
#ifndef TREES_AVL_H
#define TREES_AVL_H

#include <iostream>
#include "Student.h"
#include<map>
using namespace std;

class AVL {

public:
	Node* root;
	AVL();
	Node* createNode(student s);
	Node* rotateleft(Node* root);
	Node* rotateright(Node* root);
	int height(Node* root);
	Node* add_student(Node* root, student s);
	Node* delete_student(Node* root, student s);
	Node* findmin(Node* root);
	bool search_student(Node* root, int id);
	void insert();
	void insertStudent(student s);
	void delete_std(int id);
	void search(int id);
	void printReq(Node* cur);
	void printInOrder();
	bool validData(string& n, string& dep, int& id, double& gpa);
	Node* balanceBST(Node* root);
	int start();
	map<string, int> depMap;

};

#endif //TREES_AVL_H
