#include "AVL.h"
#include <regex>

AVL::AVL()
{
	root = NULL;
}


Node* AVL::createNode(student s)
{
	Node* newNode = new Node(s);
	newNode->height = 1;
	return newNode;

}

Node* AVL::rotateleft(Node* root)
{
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}
Node* AVL::rotateright(Node* root)
{
	Node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}


int AVL::height(Node* root)
{
	if (root == nullptr)
		return 0;
	return root->height;
}

Node* AVL::balanceBST(Node* root)
{
	if (root == nullptr) return root;
	root->left = balanceBST(root->left);
	root->right = balanceBST(root->right);
	int l = height(root->left), r = height(root->right);
	int bf = l - r;
	if (bf > 1) {
		if (height(root->left->left) < height(root->left->right)) {
			root->left = rotateleft(root->left);
		}
		return  balanceBST(rotateright(root));
	}
	else if (bf < -1) {
		if (height(root->right->right) < height(root->right->left)) {
			root->right = rotateright(root->right);
		}
		return  balanceBST(rotateleft(root));
	}
	return root;
}

Node* AVL::add_student(Node* root, student s)
{
	if (root == nullptr) {
		root = createNode(s);
		cout << "The student is added.\n";
		return root;
	}
	//check if already exist return 
	else if (root->value.getID() == s.getID()) {
		cout << "The student is already exist.\n";
		return root;
	}
	else if (s.getID() < root->value.getID()) {
		root->left = add_student(root->left, s);
		root = balanceBST(root); // balance the tree after adding a new Node
	}
	else if (s.getID() > root->value.getID()) {
		root->right = add_student(root->right, s);
		root = balanceBST(root); // balance the tree after adding a new Node
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}

bool AVL::search_student(Node* root, int id)
{
	if (root == nullptr) {
		cout << "This student is not exist" << endl;
		return false;
	}
	if (id < root->value.getID()) {
		search_student(root->left, id);
	}
	else if (id > root->value.getID()) {
		search_student(root->right, id);
	}
	else {
		cout << root->value << endl;
		return true;
	}
}

bool AVL::validData(string& n, string& dep, int& id, double& gpa) {

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

void AVL::insert() {
	string n, dep;
	double gpa; int id;
	bool valid = 0;
	while (!valid) {
		cout << "Enter student id integer ,please : " << endl;
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
	student s(n, dep, id, gpa);

	root = add_student(root, s);
	//add dep to map if found increase count if not add it
	if (depMap.find(dep) != depMap.end()) {
		depMap[dep]++;
	}
	else {
		depMap[dep] = 1;
	}
}

void AVL::search(int id)
{

	search_student(root, id);

}
Node* AVL::delete_student(Node* root, student s)
{
	if (root == nullptr) {
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
		if (root->left == nullptr && root->right == nullptr) {
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr) {
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr) {
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			Node* temp = findmin(root->right);
			root->value = temp->value;
			root->right = delete_student(root->right, temp->value);
		}
	}
	if (root == nullptr)
	{
		cout << " The student is deleted " << endl;
		return root;
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	root = balanceBST(root);
	return root;

}

void AVL::delete_std(int id)
{
	student s;
	s.setID(id);

	root = delete_student(root, s);
}

Node* AVL::findmin(Node* root)
{
	if (root == nullptr)
		return nullptr;
	else if (root->left == nullptr)
		return root;
	else
		return findmin(root->left);
}

int AVL::start()
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

void AVL::printReq(Node* cur)
{
	if (cur == nullptr)
		return;

	printReq(cur->left);
	cout << cur->value<< endl;
	printReq(cur->right);

}

void AVL::printInOrder()
{
	auto it = depMap.begin();
	for (; it != depMap.end(); it++) {
		if (it->second > 0) {
			cout << "Department: " << it->first << " has " << it->second << " students" << endl << "All students  are: " << endl;
		}
	}
	printReq(root);

}

void AVL::insertStudent(student s) {
	root = add_student(root, s);
	//add dep to map if found increase count
	depMap[s.getDepart()] = 1;
}
