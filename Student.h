
#ifndef TREES_STUDENT_H
#define TREES_STUDENT_H

#include <iostream>

using namespace std;
template<class T>
struct Node {
    T value;
    Node* left, * right;

    Node(T val) {
        value = val;
        left = right = nullptr;
    }
};
class student {
protected:
	string name, department;
	double GPA;
public:
    int ID;
    student() {
		name = department = "";
	}
	student(string n, string dep, int id, double gpa) {
		name = n; department = dep;
		ID = id; GPA = gpa;
	}
    int getID(){return ID;}
    double getGPA(){return GPA;}
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
