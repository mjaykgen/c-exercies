#include<iostream>
using namespace std;
struct TreeNode {
	string data;
	TreeNode* left = nullptr, * right = nullptr;
};
struct BST {
	TreeNode* root = nullptr;
	void insert(string num) {
		TreeNode* n = new TreeNode;
		n->data = num;
		TreeNode* cur = root, * parent = nullptr;
		while (cur != nullptr) {
			if (cur->data < num) {
				parent = cur;
				cur = cur->right;
			}
			else if (cur->data > num) {
				parent = cur;
				cur = cur->left;
			}
			else {
				cout << num << " exists already\n";
				return;
			}
		}
		if (parent != nullptr) {
			if (parent->data < num)
				parent->right = n;
			else parent->left = n;
		}
		else root = n;
		cout << num << " inserted";
	}
	bool search(TreeNode* n, string num) {
		if (n == nullptr)
			return false;
		if (n->data == num)
			return true;
		if (n->data < num)
			return search(n->right, num);
		return search(n->left, num);
	}
	void inOrder(TreeNode* t) {
		if (t == nullptr)
			return;
		inOrder(t->left);
		cout << t->data << " ";
		inOrder(t->right);
	}
	//count the number of nodes in a binary tree
	int countNodes(TreeNode* t) {
		if (t == nullptr)
			return 0;
		return 1 + countNodes(t->left) + countNodes(t->right);
	}
};

/*
* write a main program that reads in the names of a list of students (user choice when to stop)
* display the names alphabetically
* show the number of students entered
* search for a particular student.
*/
int main() {
	BST studentsTree;// = { nullptr };
	string name;
	char choice;
	do {
		cout << "Enter student name:";
		cin >> name;
		//insert in the tree
		studentsTree.insert(name);
		cout << "\nContinue?(y/n):";
		cin >> choice;
	} while (choice != 'n' && choice != 'N');
	//display alphabetically
	//if(studentsTree.root ==nullptr )
	cout << "List content:";
	studentsTree.inOrder(studentsTree.root);
	//show the number of students
	cout << "\nNumber of students in the list:" << studentsTree.countNodes(studentsTree.root) << endl;
	//search for a student
	cout << "Enter the name to look for:";
	cin >> name;
	if (studentsTree.search(studentsTree.root, name))
		cout << name << " is found\n";
	else cout << "No student with name:" << name << "\n";
	
	return 0;
}