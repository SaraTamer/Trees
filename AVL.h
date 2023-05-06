
#ifndef TREES_AVL_H
#define TREES_AVL_H

#include <iostream>
#include "Student.h"

using namespace std;

#include<iostream>
using namespace std;
struct student {
    int id;
    string name;
    double gpa;
    string dept;
};
struct node {
    student value;
    node* left=NULL;
    node* right=NULL;
	int height;
};

class AVL {
public:
    node* root;
	node* createnode(student s)
	{
		node* newNode = new node;
		newNode->value = s;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
    node* rotateleft(node* root) {
        node* temp = root->right;
        root->right = root->left;
        temp->left = root;
        //root = temp;
		
		return root;

    }
    node* rotateright(node* root) {
        node* temp = root->left;
        root->left = root->right;
        temp->right = root;
      //  root = temp;
		return root;

    }
    int height(node* root) {
        if (root == NULL) {
            return -1;
        }
        int left_height = height(root->left);
        int right_height = height(root->right);
        return max(left_height, right_height) + 1;
    }
	node* add_student(node* root, student s) {
		if (root == NULL)
		{
			return  createnode(s);
		}
		else if (s.id < root->value.id)
		{
			root->left = add_student(root->left, s);
			if (height(root->left) - height(root->right) == 2)
			{
				if (s.id < root->left->value.id)
					return rotateright(root);
				else
				{
					return rotateleft(root->left);///??
					return rotateright(root);     ///??
				}
			}
		}
		else if (s.id > root->value.id)
		{
			root->right = add_student(root->right,s);
			if (height(root->right) - height(root->left) == 2)
			{
				if (s.id > root->right->value.id)
					return rotateleft(root);
				else
				{
					return rotateright(root->right);///??
					return rotateleft(root);        ///??
				}
			}
		}
		else
			return root;
		root->height = max(height(root->left), height(root->right)) + 1;
		return root;

	}
	//void delete_student(node* root, student s) {
	//	if (root == NULL) {
	//		return;
	//	}

	//	if (s.id < root->value.id) {
	//		delete_student(root->left, s);
	//	}
	//	else if (s.id > root->value.id) {
	//		delete_student(root->right, s);
	//	}
	//	else {
	//		if (root->left == NULL && root->right == NULL) {
	//			root = NULL;
	//		}
	//		else if (root->left == NULL) {
	//			root = root->right;
	//		}
	//		else if (root->right == NULL) {
	//			root = root->left;
	//		}
	//		else {
	//			node* temp = root->right;
	//			while (temp->left != NULL) {
	//				temp = temp->left;
	//			}
	//			root->value = temp->value;
	//			delete_student(root->right, temp->value);
	//		}
	//	}
	//	if (root == NULL) {
	//		return;
	//	}
	//	//	int balance = height(root);
	//	if (height(root->left) - height(root->right) == 2)
	//	{
	//		if (height(root->left->left) - height(root->left->right) == 1)
	//			rotateright(root);
	//		else
	//		{
	//			rotateleft(root->left);
	//			rotateright(root);
	//		}
	//	}
	//	else if (height(root->right) - height(root->left) == 2)
	//	{
	//		if (height(root->right->right) - height(root->right->left) == 1)
	//			rotateleft(root);
	//		else
	//		{
	//			rotateright(root->right);
	//			rotateleft(root);
	//		}
	//	}

	//}
	void insert(student s) {
		root =  add_student(root,s);
	}
	void search_student(node* root, int id) {
		if (root == NULL) {
			cout << "This student is not exist" << endl;
			return;
		}
		if (id < root->value.id) {
			search_student(root->left, id);
		}
		else if (id > root->value.id) {
			search_student(root->right, id);
		}
		else {
			cout << "Student ID: " << root->value.id << endl;
			cout << "Student Name: " << root->value.name << endl;
			cout << "Student GPA: " << root->value.gpa << endl;
			cout << "Student Department: " << root->value.dept << endl;
		}
	}


 
};
int main() 
{
		student s1 = { 1, "Ali", 3.5, "CS" };
		student s2 = { 2, "Ahmed", 3.2, "CS" };
		student s3 = { 3, "Sara", 3.8, "CS" };
		student s4 = { 4, "Sana", 3.9, "CS" };
		student s5 = { 5, "Hassan", 3.1, "CS" };
		student s6 = { 6, "Hussain", 3.3, "CS" };
		student s7 = { 7, "Khalid", 3.4, "CS" };
		student s8 = { 8, "Kamran", 3.6, "CS" };
		student s9 = { 9, "Ayesha", 3.7, "CS" };
		student s10 = { 10, "Aisha", 3.0, "CS" };
		
		//add student to tree
		AVL tree;
		tree.insert(s1);
		tree.insert(s2);
		
		tree.search_student(tree.root, 1);
		
		
		
		//tree.delete_student(s1);
		//tree.delete_student(s2);
		//tree.delete_student(s3);
		//tree.delete_student(s4);
		//tree.delete_student(s5);
		//tree.delete_student(s6);
		//tree.delete_student(s7);
		//tree.delete_student(s8);
		//tree.delete_student(s9);
		//tree.delete_student(s10);
		return 0;
	}

#endif //TREES_AVL_H
