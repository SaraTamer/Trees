

#ifndef TREES_HEAPSTUDENT_H
#define TREES_HEAPSTUDENT_H

#include "Student.h"

class HeapStudent : public student{
public:
    HeapStudent(string n, string dep, int id, double gpa) {
        name = n;
        department = dep;
        ID = id;
        GPA = gpa;
    }

    bool operator==(student other) {
        return (GPA == other.getGPA());
    }
    bool operator< (student other) {
        return (GPA < other.getGPA());
    }
    bool operator> (student other) {
        return (GPA > other.getGPA());
    }
};

#endif //TREES_HEAPSTUDENT_H
