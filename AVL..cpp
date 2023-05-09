#include "AVL.h"
#include <regex>
template<class T>
AVL<T>::AVL()
{
	root = NULL;
}

template<class T>
node<T>* AVL<T>::createnode(student s)
{
	node<T>* newnode = new node<T>;
	newnode->value = s;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 1;
	return newnode;
	
}

template<class T>
node<T>* AVL<T>::rotateleft(node<T>* root)
{
	node<T>* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

template<class T>
node<T>* AVL<T>::rotateright(node<T>* root)
{
	node<T>* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

template<class T>
int AVL<T>::height(node<T>* root)
{
	if (root == NULL)
		return 0;
	return root->height;
}
template<class T>
node<T>* AVL<T>::balanceBST(node<T>* root)
{
 if(root==NULL) return root;
        root->left= balanceBST(root->left);
        root->right= balanceBST(root->right);
        int l = height(root->left), r = height(root->right);
        int bf = l -r ;
        if(bf > 1){
            if (height(root->left->left)<height(root->left->right)){
                root->left=rotateleft(root->left);
            }
            return  balanceBST(rotateright(root));
        }else if (bf<-1){
            if (height(root->right->right)<height(root->right->left)){
                root->right=rotateright(root->right);
            }
            return  balanceBST(rotateleft(root));
        }
        return root;
}
template<class T>
node<T>* AVL<T>::add_student(node<T>* root, student s)
{	
	if (root == NULL) {
        root = createnode(s);
        root->height = 1;
        cout << "The student is added.\n";
        return root;
    }
    //check if already exist return 
    else if (root->value.ID == s.getID()) {
        cout << "The student is already exist.\n";
        return root;
    }
    else if (s.getID() < root->value.ID) {
        root->left = add_student(root->left, s);
        root = balanceBST(root); // balance the tree after adding a new node
    }
    else if (s.getID() > root->value.ID) {
        root->right = add_student(root->right, s);
        root = balanceBST(root); // balance the tree after adding a new node
    }
    root->height = max(height(root->left), height(root->right)) + 1;
    return root;
}
template<class T>
bool AVL<T>::search_student(node<T>* root, int id)
{
	if (root == NULL) {
		cout << "This student is not exist" << endl;
		return false;
	}
	if (id < root->value.ID) {
		search_student(root->left, id);
	}
	else if (id > root->value.ID) {
		search_student(root->right, id);
	}
	else {
		cout << "Student ID: " << root->value.ID << endl;
		cout << "Student Name: " << root->value.name << endl;
		cout << "Student GPA: " << root->value.gpa << endl;
		cout << "Student Department: " << root->value.dept << endl;
		cout << "================================================= " << endl;
		return true;
	}
}
template<class T>
bool AVL<T>:: validData(string& n, string& dep, int& id, double& gpa) {

	regex validN("[a-zA-Z]+ [a-zA-Z]+"), validD("[A-Z][A-Z]");
	//check also that id and GPA is integer not string using regex
	regex validID("[0-9]+"), validGPA("[0-9]+.[0-9]+");
	
	
	if (id < 0 || id > 99999999 || !regex_match(to_string(id), validID)) {
		
		cout << "Invalid ID" << endl;
		return false;
	}
	//GPA
	if (gpa < 0 || gpa > 4 || !regex_match(to_string(gpa), validGPA)) {
		cout << "Invalid GPA" << endl;
		return false;
	}
	
	return true;
}
template<class T>
void AVL<T>::insert() {
	string n, dep;
	double gpa; int id;
	bool valid = 0;
	while (!valid) {
		cout << "Enter student id integer ,please : "<<endl;
		cout << "id: ";
		cin >> id; cin.ignore();
		cout << "Enter student name ,please : " << endl;
		cout << "Name: ";
		std::getline(std::cin, n);
		cout << "Enter student GPA integer ,please : " << endl;
		cout << "GPA: ";
		cin >> gpa; cin.ignore();
		cout << "Enter student department ,please : " << endl;
		cout << "Department: ";
		std::getline(std::cin, dep);
		valid = validData(n, dep, id, gpa);	
	}
	//add this student to the tree
	student s(n,dep, id,gpa);

	root = add_student(root, s);
	//add dep to map if found increase count if not add it
	if (depMap.find(dep) != depMap.end()) {
		depMap[dep]++;
	}
	else {
		depMap[dep] = 1;
	}
}
template<class T>
void AVL<T>::search(int id)
{
	
	search_student(root, id);
	
}
template<class T>
node<T>* AVL<T>::delete_student(node<T>* root, student s)
{
	if (root == NULL) {
		cout << " The student is not exist " << endl;
		return root;
	}
	else if (s.getID() < root->value.getID()) {
		root->left = delete_student(root->left, s);
	}
	else if (s.getID() > root->value.getID()) {
		root->right = delete_student(root->right, s);
	}
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->left == NULL) {
			node<T>* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL) {
			node<T>* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			node<T>* temp = findmin(root->right);
			root->value = temp->value;
			root->right = delete_student(root->right, temp->value);
		}
	}
	if (root == NULL)
	{
		cout << " The student is deleted " << endl;
		return root;
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	root = balanceBST(root);
	return root;
	
}
template<class T>
void AVL<T>::delete_std(int id)
{
	student s;
	s.ID = id;

	root = delete_student(root, s);
}
template<class T>
node<T>* AVL<T>::findmin(node<T>* root)
{
	if (root == NULL)
		return NULL;
	else if (root->left == NULL)
		return root;
	else
		return findmin(root->left);
}
template<class T>
int AVL<T>::start()
{
	int option;
	cout << "Choose one of the following options:\n1. Add student\n2. Remove student\n3. Search student\n"
		<< "4. Print All(sorted by id)\n5. Return to main menu\n";
	cin >> option;
	while (option < 1 || option>5) {
		cout << "Invalid choice.\n Please choose one of the following options:\n1. Add student\n2. Remove student\n3. Search student\n"
			<< "4. Print All(sorted by id)\n5. Return to main menu\n" << "Enter number of option:";
		cin >> option;
	}
	switch (option)
	{
	case 1: {
		cout << "your choice 1\n";
		insert();
		break;
	}
	case 2: {
		cout << "your choice 2\n";
		int id;
		cout << "Enter the id of the student you want to delete: ";
		cin >> id;
		delete_std(id);

		break;
	}
	case 3: {
		cout << "your choice 3\n";
		int id;
		cout << "Enter the id of the student you want to search for: ";
		cin >> id;
		search(id);
		break;
	}
	case 4: {
		cout << "your choice 4\n";
		printInOrder();

		break;
	}
	case 5: {
		cout << "your choice 5\n";
		break;
	}

	default:
		break;
	}
	return option;
}
template<class T>
void AVL<T>::printReq(node<T>* cur)
{
	if (cur == NULL)
		return;
	
	printReq(cur->left);
	cout << "Student ID: " << cur->value.ID << endl;
	cout << "Student Name: " << cur->value.name << endl;
	cout << "Student GPA: " << cur->value.gpa << endl;
	cout << "Student Department: " << cur->value.dept << endl;
	cout << "================================================= " << endl;
	printReq(cur->right);
	
}

template<class T>
void AVL<T>::printInOrder()
{
	auto it = depMap.begin();
	for (; it != depMap.end(); it++) {
		if (it->second > 0) {
			cout << "Department: " << it->first << " has " << it->second << " students" << endl << "All students  are: " << endl;
		}
	}
	printReq(root);
	
}
