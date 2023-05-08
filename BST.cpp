#include"BST.h"
template<class T>
void BST<T>::insert(T val) {
	Node<T>* addedStudent = new Node<T>(val);
	if (root == nullptr) {
		root = addedStudent;
		return;
	}
	Node<T>* cur = root;
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
template<class T>
void printReq(Node<T>* cur) {
	if (cur == nullptr) {
		return;
	}
	Node<T>* r = cur;

	printReq(cur->left);
	cout << cur->value << "\n";
	printReq(cur->right);
}
template<class T>
void BST<T>::printInOrder() {
	printReq(root);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int BSTStudent::start() {
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
		cout << "your choice 2\n";
		break;
	}
	case 3: {
		cout << "your choice 3\n";
		break;
	}
	case 4: {
		//PrintAll();
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
void BSTStudent::AddStudent() {
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
	students.insert(student(n, dep, id, gpa));
	cout << "The student is added.\n";
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BSTStudent::PrintAll() {
	students.printInOrder();
}



