#include"BST.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int BST::start() {
	int option;
	cout << "Choose one of the following options:\n1. Add student\n2. Remove student\n3. Search student\n"
		<< "4. Print All(sorted by id)\n5. Return to main menu\nEnter number of option:";
	cin >> option;
	while (option < 1 || option>5) {
		cout << "Invalid choice.\n Please choose one of the following options:\n1. Add student\n2. Remove student\n3. Search student\n"
			<< "4. Print All(sorted by id)\n5. Return to main menu\n"<<"Enter number of option:";
		cin >> option;
	}
	switch (option)
	{
	case 1: {
		AddStudent();
		break;
	}
	case 2: {
		cout << "your choice 2\n";
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
		cout << "your choice 5\n";

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

bool validData(string& n, string& dep, int& id, double& gpa) {

	regex validN("[a-zA-Z]+ [a-zA-Z]+"), validD("[A-Z][A-Z]");
	//if (id < 1) {
	//	cout << "Invalid id must be positive integer\n";
	//	
	//}
	//else if (!regex_match(n, validN)) {
	//	cout << "Invalid name of student must be a characters \n";
	//}
	//else if (!regex_match(dep, validD)) {
	//	cout << "Invalid, As deparatment must be two upercase characters (if deparatment is Computer Science Enter CS)\n";
	//}
	//else {
	//	return true;
	//}
	//return false;
    return true;
}
void BST::AddStudent() {
	string n, dep;
	double gpa; int id;
	bool valid = 0;
	while (!valid) {
		cout << "id: ";
		cin >> id; cin.ignore();
		cout << "Name: ";
		std::getline(std::cin, n);
		cout << "GPA: ";
		cin >> gpa; cin.ignore();
		cout << "Department: ";
		std::getline(std::cin, dep);
		valid = validData(n, dep, id, gpa);
	}
	insert(student(n, dep, id, gpa));
	cout << "The student is added.\n";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BST::SearchStudent(int id) {
	if (id < 0) {
		cout << "Invalid ID must be positive integer\n";
	}
	Node* cur = root;
	while (cur != nullptr) {
		if (cur->value.getID() == id) {
			cout << "Student is found.\n" << cur->value << "\n";
			return;
		}
		else if (cur->value.getID() < id) {
			cur = cur->right;
		}
		else if (cur->value.getID() > id) {
			cur = cur->left;
		}
	}
	cout << "Student is found.\n";
}
