//
// Created by Apex on 5/5/2023.
//

#ifndef TREES_STUDENT_H
#define TREES_STUDENT_H

#include <iostream>

using namespace std;

struct student{
    int id;
    string name;
    double gpa;
    string dept;
};
struct node{
    student value;
    node* left;
    node* right;
};
#endif //TREES_STUDENT_H
