#include "MinHeap.h"

void MinHeap::heapify(vector<student> vec, int size, int parent)
{
    int l = left(parent);
    int r = right(parent);
    int minimum = parent;
    double m = vec[minimum].getGPA();
    double lValue = vec[l].getGPA();
    if(l < size && m > lValue)
        minimum = l;
    m = vec[minimum].getGPA();
    double rValue = vec[l].getGPA();
    if(r < size && m > rValue)
        minimum = r;
    if(minimum != parent)
    {
        swap(vec[minimum] , vec[parent]);
        heapify(vec, size,minimum);
    }
}
 
void MinHeap::buildHeap( vector<student> vec, int size)
{
    for(int i = size/2 - 1; i >= 0; i--)
    {
        heapify(vec,size,i);
    }
}
void MinHeap::heapSort(vector<student> vec, int size)
{
    buildHeap(vec,size);
    for(int i = size - 1;i >= 0; i--)
    {
        swap(vec[0], vec[i]);
        heapify(vec,i,0);
    }
}
void MinHeap::print()
{
    heapSort(myVec, myVec.size());
    for(auto i: myVec)
    {
        cout << i << '\n';
    }
}

void MinHeap::loadVec()
{
    fstream db;
    db.open("Students.txt", ios::in);
    if (db.fail()) {
        db.close();
        db.open("Students.txt", ios::out);
        db.close();
    }
    else {
        int nStudents;
        db >> nStudents;
        for(int i = nStudents ; i > 0 ; i--) {
            string name, department, temp;
            int id;
            double GPA;
            db >> id;
            db >> temp;
            getline(db, name);
            db >> GPA;
            db >> department;
            cout << temp;
            //getline(db, department);
            temp += name;

            student s (temp, department, id, GPA);
            //call insert that takes student
            this->insert(s);

        }
    }
    //    string id, name, dept, gpa;
//    while(db)
//    {
//        getline(db,id);
//        getline(db,name);
//        getline(db,gpa);
//        getline(db,dept);
//        student s( string(name), string(dept), stoi(string(id)), stod(string(gpa)));
//        myVec.push_back(s);
//    }

//    buildHeap(myVec,myVec.size());
//    db.close();
}
 
void MinHeap::insert(student item)
{
    myVec.push_back(item);
    buildHeap(myVec,myVec.size());
}
 
void MinHeap::start()
{
//    this->loadVec();
    cout << "Choose one of the following options:\n"
            "1. Add student\n"
            "2. Print All (sorted by gpa)\n";
    int ch;
    cin >> ch;
    if(ch == 1) {
        int id;
        double gpa;
        string name, dept;
        cout << "id: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "GPA: ";
        cin >> gpa;
        cout << "Department: ";
        cin >> dept;
        student student(name, dept, id, gpa);
        this->insert(student);
    }
    else if(ch == 2)
        this->print();
}
