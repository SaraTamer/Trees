
AVL::AVL()
{
	root = NULL;
}

node* AVL::createnode(student s)
{
	node* newnode = new node;
	newnode->value = s;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 1;
	return newnode;
	
}

node* AVL::rotateleft(node* root)
{
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

node* AVL::rotateright(node* root)
{
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	root->height = max(height(root->left), height(root->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}

int AVL::height(node* root)
{
	if (root == NULL)
		return 0;
	return root->height;
}

node* AVL::add_student(node* root, student s)
{	
	if (root == NULL) {
		root = createnode(s);
		root->height = 1;
		cout << "The student is added.\n";
		return root;
	}
	//check if already exist return 
	else if (root->value.id == s.id) {
		cout << "The student is already exist.\n";
			return root;
	}
	else if (s.id < root->value.id) {
		root->left = add_student(root->left, s);
		if (height(root->left) - height(root->right) == 2) {
			if (s.id < root->left->value.id) {
				root = rotateright(root);
			}
			else {
				root->left = rotateleft(root->left);
				root = rotateright(root);
			}
		}
		
	}
	else if (s.id > root->value.id) {
		root->right = add_student(root->right, s);
		if (height(root->right) - height(root->left) == 2) {
			if (s.id > root->right->value.id) {
				root = rotateleft(root);
			}
			else {
				root->right = rotateright(root->right);
				root = rotateleft(root);
			}
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}
bool AVL::search_student(node* root, int id)
{
	if (root == NULL) {
		cout << "This student is not exist" << endl;
		return false;
	}
	if (id < root->value.id) {
		search_student(root->left, id);
	}
	else if (id > root->value.id) {
		search_student(root->right, id);
	}
	else {
		cout << "Student ID: " << root->value.id << endl;
		cout << "Student Name: " << root->value.name << endl;
		cout << "Student GPA: " << root->value.gpa << endl;
		cout << "Student Department: " << root->value.dept << endl;
		cout << "================================================= " << endl;
		return true;
	}
}
bool AVL:: validData(string& n, string& dep, int& id, double& gpa) {

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
	student s;
	s.name = n;
	s.id = id;
	s.gpa = gpa;
	s.dept = dep;
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
void AVL::printReq(node* cur)
{
	if (cur == NULL)
		return;
	
	printReq(cur->left);
	cout << "Student ID: " << cur->value.id << endl;
	cout << "Student Name: " << cur->value.name << endl;
	cout << "Student GPA: " << cur->value.gpa << endl;
	cout << "Student Department: " << cur->value.dept << endl;
	cout << "================================================= " << endl;
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
