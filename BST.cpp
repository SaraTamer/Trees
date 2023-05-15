#include"BST.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int BST::start() {
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
		AddStudent();
		break;
	}
	case 2: {
		int id;
		cout << "id:";
		cin >> id;
		RemoveStudent(id);
		break;
	}
	case 3: {
		int id;
		cout << "id:";
		cin >> id;
		SearchStudent(id);
		break;
	}
	case 4: {
		PrintAll();
		break;
	}
	case 5: {
		option = 0;
		break;
	}

	default:
		break;
	}
	return option;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BST::insert(student val) {
	Node* addedStudent = new Node(val);
	if (root == nullptr) {
		root = addedStudent;
		return;
	}
	Node* cur = root;
	while (cur != nullptr) {
		if (cur->value < addedStudent->value) {//insert in right
			if (cur->right == nullptr) {
				cur->right = addedStudent;
				break;
			}
			cur = cur->right;
		}
		else {
			if (cur->left == nullptr) {
				cur->left = addedStudent;
				break;
			}
			cur = cur->left;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int departments[4];
void printReq(Node* cur) {
	if (cur == nullptr) {
		return;
	}
	printReq(cur->left);
	cout << cur->value << "\n";
	string dep = cur->value.getDepart();
	if (dep == "CS") {
		departments[0]++;
	}
	else if (dep == "IT") {
		departments[1]++;
	}
	else if (dep == "DS") {
		departments[2]++;
	}
	else {
		departments[3]++;
	}
	printReq(cur->right);
}
void BST::PrintAll() {

	printReq(root);
	cout << "CS " << departments[0] << " Students\nIT " << departments[1] << " Students\n";
	cout << "DS " << departments[2] << " Students\nIS " << departments[3] << " Students\n";
}
void BST::AddStudent() {
	string n, dep;
	double gpa; int id;
	bool valid = 0;
	cout << "id: ";
	cin >> id;
	while (id < 1) {
		cout << "Invalid id must be positive integer\nid:";
		cin >> id;
	}
	Node* found = Search(id);
	while (found != nullptr) {
		cout << "This ID already exists. Please enter another one\nid:";
		cin >> id;
		found = Search(id);
	}
	cin.ignore();
	cout << "Name: ";
	std::getline(std::cin, n);
	while (n.size() < 2) {
		cout << "Invalid name must be more than one character\n";
		cout << "Name: ";
		std::getline(std::cin, n);
	}
	cout << "GPA: ";
	cin >> gpa;
	while (gpa < 1 || gpa>4) {
		cout << "Invalid gpa must be positive and less than or equal 4\nGPA: ";
		cin >> gpa;
	}
	cin.ignore();
	cout << "Department: ";
	std::getline(std::cin, dep);
	while (dep.size() < 2 ||
		((dep != "CS") && (dep != "DS") && (dep != "IS") && (dep != "IT") && (dep != "AI"))) {
		cout << "Invalid department must be more than one character and one of the following (CS, DS, IS, IT, AI)\n";
		cout << "Department: ";
		std::getline(std::cin, dep);
	}
	insert(student(n, dep, id, gpa));
	cout << "The student is added.\n";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Node* BST::Search(int id) {
	Node* cur = root;
	while (cur != nullptr) {
		if (cur->value.getID() == id) {
			return cur;
		}
		else if (cur->value.getID() < id) {
			cur = cur->right;
		}
		else if (cur->value.getID() > id) {
			cur = cur->left;
		}
	}
	return cur;
}
void BST::SearchStudent(int id) {
	if (id < 0) {
		cout << "Invalid ID must be positive integer\n";
		return;
	}
	Node* cur = Search(id);
	if (cur != nullptr) {
		cout << "Student is found.\n" << cur->value << "\n";
	}
	else
		cout << "Student is not found.\n";
}


void BST::RemoveStudent(int id) {
	if (id < 1) {
		cout << "Invalid ID must be positive integer\n";
		return;
	}
	Node* cur = Search(id), * parent = root;
	if (cur == nullptr) {
		cout << "There is no student with such an ID\n";
	}
	else {
		cout << "Student is found.\n" << cur->value << "\nStudent is deleted.\n";
		bool hasParent = true;
		if (root->value.getID() == id) {
			hasParent = false;
			if (root->left == nullptr && root->right == nullptr) {
				root = nullptr;
				delete cur;
				return;
			}
		}

		while (hasParent)
		{
			if (parent->value.getID() >= id) {
				if (parent->left->value.getID() != id)
					parent = parent->left;
				else
					break;
			}
			else {
				if (parent->right->value.getID() != id)
					parent = parent->right;
				else
					break;
			}
		}
		Node* successor = nullptr;
		if (cur->left == nullptr && cur->right == nullptr) {
			successor = nullptr;
		}
		else if (cur->right != nullptr) {//smallest from right
			successor = cur->right;
			while (successor != nullptr) {
				if (successor->left == nullptr) {
					if (successor != cur->right) {
						successor->right = cur->right;
					}
					break;
				}
				else {//now successor equals his parent
					if (successor->left->left == nullptr) {
						Node* succParent = successor;
						successor = successor->left;
						succParent->left = successor->right;
					}
					else
						successor = successor->left;
				}
			}
			successor->left = cur->left;
			cur->right = cur->left = nullptr;
		}
		else if (cur->left != nullptr) {//eement to be deleted has no right, just has left  
			successor = cur->left;
			cur->left = nullptr;
		}
		if (hasParent) {
			if (parent->value.getID() >= id)
				parent->left = successor;
			else
				parent->right = successor;
		}
		else {
			root = successor;
		}
		delete cur;
	}
}
