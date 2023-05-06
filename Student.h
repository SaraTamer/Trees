//
// Created by Apex on 5/5/2023.
//

#ifndef TREES_STUDENT_H
#define TREES_STUDENT_H

#include <iostream>

using namespace std;
class student {
	string name, department;
	double GPA;
	int ID;
public:
	student() {
		name = department = "";
	}
	student(string n, string dep, int id, double gpa) {
		name = n; department = dep;
		ID = id; GPA = gpa;
	}
	bool operator==(student other) {
		return (ID == other.ID);
	}
	bool operator< (student other) {
		return (ID < other.ID);
	}
	bool operator> (student other) {
		return (ID > other.ID);
	}
	friend ostream& operator << (ostream& out, const student& s) {
		out << "[" << s.ID << ", " << s.name << ", " << s.GPA << ", " << s.department << "]";

		return out;
	}
};
#endif //TREES_STUDENT_H
