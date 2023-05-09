#include "MinHeap.h"

template<class T>
void MinHeap<T>::heapify(vector<T> vec, int size, int parent)
{
    int l = left(parent);
    int r = right(parent);
    int minimum = parent;
    if(l < size && vec[minimum].getGPA() > vec[l].getGPA())
        minimum = l;
    if(r < size && vec[minimum].getGPA() > vec[r].getGPA())
        minimum = r;
    if(minimum != parent)
    {
        swap(vec[minimum] , vec[parent]);
        heapify(vec, size,minimum);
    }
}
template<class T>
void MinHeap<T>::buildHeap(vector<T> vec, int size)
{
    for(int i = size/2 - 1; i >= 0; i--)
    {
        heapify(vec,size,i);
    }
}
template<class T>
void MinHeap<T>::heapSort(vector<T> vec, int size)
{
    buildHeap(vec,size);
    for(int i = size/2 - 1;i >= 0; i--)
    {
        swap(vec[0], vec[i]);
        heapify(vec,i,0);
    }
}
template<class T>
void MinHeap<T>::print()
{
    heapSort(myVec, myVec.size());
    for(auto i: myVec)
    {
        cout << i << '\n';
    }
}

template<class T>
void MinHeap<T>::loadVec()
{
    ifstream db;
    db.open("Database.txt");
    string id, name, dept, gpa;
    while(db)
    {
        getline(db,id);
        getline(db,name);
        getline(db,gpa);
        getline(db,dept);
        student s( string(name), string(dept), stoi(string(id)), stod(string(gpa)));
        myVec.push_back(s);
    }

    buildHeap(myVec,myVec.size());
    db.close();
}
template<class T>
void MinHeap<T>::insert(T item)
{
    myVec.push_back(item);
    buildHeap(myVec,myVec.size());
}
template<class T>
void MinHeap<T>::studentMenu()
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