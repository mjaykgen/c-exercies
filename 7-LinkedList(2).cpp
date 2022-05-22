#include<iostream>
using namespace std;

//structure for the node
struct Node {
	int data;
	Node* next = nullptr;	
};
struct LinkedList {
	Node* head = nullptr;
	void append( int num) {
		//go to end and adjust the pointer of tail 
		//to a new node that has the num value
		//if the list is empty, head becomes this new node
		Node* n = new Node;
		n->data = num;
		if (head == nullptr)
			head = n;
		else {
			Node* cur = head;
			while (cur->next != nullptr) {
				cur = cur->next;
			}
			cur->next = n;
		}
		cout << num << " is appended\n";

	}
	void insert(int num) {
		//search for the correct position of num and insert in between 
		//keep track of prev	
		Node* n = new Node;
		n->data = num;
		if (head == nullptr)
			head = n;
		else {
			Node* prev = nullptr, * cur = head;
			while (cur != nullptr && cur->data < num) {
				prev = cur;
				cur = cur->next;
			}
			if (prev != nullptr)
				prev->next = n;
			else head = n;
			n->next = cur;//whether null or not

		}
		cout << num << " inserted\n";

	}
	
	void deleteNode(int num) {
		if (head == nullptr)
			cout << "List is empty\n";
		else {
			//search for node and keep track of prev to adjust pointer
			Node* cur = head, * prev = nullptr;
			while (cur != nullptr && cur->data != num) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == nullptr)
				cout << num << " is not found\n";
			else {
				if (prev != nullptr)//if not head
					prev->next = cur->next;
				else //delete the head
					head = head->next;
				cout << num << " deleted \n";
			}
		}
	}
	//recursive print helper
	void printR(Node* cur) {
		//base case
		if (cur == nullptr)
			return;
		cout << cur->data << " ";
		printR(cur->next);
	}
	void printAll() { //calls the recursive function and will be used in main - W11-Lab
		if (head == nullptr)
			cout << "List is empty";
		else {
			cout << "List elements are:";
			printR(head);
		}
	}
	void print() { //iterative print function
			if (head == nullptr)
				cout << "List is empty\n";
			else {
				Node* cur = head;
				cout << "List elements:";
				while (cur != nullptr) {
					cout << cur->data << " ";
					cur = cur->next;
				}
				cout << endl;
			}
	}
	void clear() {
		Node* cur = head;
		while (cur != nullptr) {		
			head=head->next;
			delete cur;	
			cur = head;
		}				\
		cout << "List cleared\n";
	}
	//recursive  search
	Node* searchElement(Node* cur, int num) { //W11-lab
		if (cur == nullptr)
			return nullptr;
		if (cur->data == num)
			return cur;
		return searchElement(cur->next, num);			
	}
	//get element at position
	Node* getElementAt(int pos) { //W11-lab
		Node* cur = head;
		while (pos > 0 && cur != nullptr) {
			cur = cur->next;
			pos--;
		}
		if (cur != nullptr)
			cout << cur->data << endl;
		return cur;//either null or value
	}
};
void swap(int element, LinkedList list) {//W11 - lab
	Node* p = list.searchElement(list.head, element);
	if (p == nullptr)
		cout << "Element is not found\n";
	else {
		if (p->next == nullptr)
			cout << "this is the last element, cannot be swapped\n";
		else {
			int temp = p->data;
			p->data = p->next->data;
			p->next->data = temp;
			cout << "Elements swapped";
		}
	}
}
int main() {
	//create a linked list - W11 - Lab
	LinkedList list;
	int num,choice;
	cout << "Enter elements to append to the list (-1 to stop)";
	cin >> num;
	while (num != -1) {
		list.append(num);
		cin >> num;
	}
	do {
		cout << "\nYour options:\n\t1-Print\n\t2-Search for an element\n\t3-Get element at position"
			<< "\n\t4-Swap element in list\n\t5-Clear list\n\t0-Exit\nEnter your choice:";
		cin >> choice;
		switch (choice) {
		case 1://print
			list.printAll(); //recursive
			cout << endl; 
			break;
		case 2://search
		{//because i am declaring res in a case
			cout << "Enter an element to search for:";
			cin >> num;
			Node* res = list.searchElement(list.head, num);
			cout << num << (res == nullptr ? " not found" : " is found") << endl;
		}
			break;
		case 3://element at pos
		{	//because res is defined in a case
			cout << "Enter the position of the element:";
			cin >> num;
			Node* res = list.getElementAt(num);
			if (res == nullptr)
				cout << "Invalid position\n";
			else cout << "Element at " << num << " is:" << res->data << endl;
		}
			break;
		case 4://swap element with its next
			cout << "Enter an element to swap with its next:";
			cin >> num;
			swap(num, list);
			break;
		case 5://clear
			list.clear();
			break;
		}
	} while (choice != 0);
	return 0;

}

