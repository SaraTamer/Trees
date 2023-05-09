
#ifndef TREES_STUDENT_H
#define TREES_STUDENT_H

#include <iostream>

using namespace std;

class student {
protected:
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
	int getID() { return ID; }
	void setID(int id) { ID = id; }
	double getGPA() { return GPA; }
	string getDepart() { return department; }
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
struct Node {
	student value;
	int height;
	Node* left, * right;

	Node(student val) {
		value = val;
		left = right = nullptr;
	}
};
#endif //TREES_STUDENT_H
