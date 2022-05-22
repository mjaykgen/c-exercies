/*
•	Week 12 – Doubly and Circular lists
o	Ex 6 – Gaddis modified: 
	Write a member function insertAtPos that inserts an element at a given position in a doubly linked list. Positions in the list start from 0. 
	Write a function that computes the sum of elements in a doubly linked list passed as parameter.
	Test your functions in the main where the user fills the list, we display then the elements and the sum of values.
o	Write a function that accepts a string as a parameter and determines whether the string is palindrome or not using a linked list or one of its variations. Test it in a main function where the user inputs a string as a parameter. The string could contain spaces. 
*/
#include<iostream>
#include<string>
using namespace std;
struct Node {
	int data;
	Node* prev = nullptr, * next = nullptr;
};
struct DoublyLL {
	Node* head = nullptr;
	
	int insertAtPos(int num, int pos) {
		Node* cur = head, *pre=nullptr;//*prev for append
		Node* n = new Node;
		n->data = num;
		int c = 0;
		while (cur != nullptr && c < pos) {
			pre = cur;
			cur = cur->next; 	
			c++;
		}		
		if (cur != nullptr) {
			if (cur->prev != nullptr) {
				cur->prev->next = n;
				n->prev = cur->prev;				
			}
			else {
				head = n;					
			}
			n->next = cur;
			cur->prev = n;
			c= -1;
		}
		else if (pos == 0) {
			head = n;
			c= -1;
		}	
		else if (pos == c) { //last element
			pre->next = n;
			n->prev = pre;
			c= -1;
		}
	    return c;
	}
	void print() {
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
	void append(int num) {
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
			n->prev = cur;//add the prev pointer
			cur->next = n;
		}
	//	cout << num << " is appended\n";

	}
};
int sum(DoublyLL list) {
	int s = 0;
	Node* cur = list.head;
	while (cur != nullptr) {
		s += cur->data;
		cur = cur->next;
	}
	return s;
}
bool isPalindrome(string s) {
	//create a doubly linked list and save in it each char
	//either change the node to be char data, or you can keep it as int 
	//so it saves the ASCII
	DoublyLL list;
	for (int i = 0; i < s.length(); i++)
		if(s[i]!=' ') //skip spaces
			list.append((int)s[i]);
	//save the last element in the list
	Node* last = list.head;
	while (last->next != nullptr)
		last = last->next;
	Node* cur = list.head;
	while (cur != last && cur->prev != last) {
		if (cur->data != last->data)
			return false;
		cur = cur->next;
		last = last->prev;
	}
	return true;
}
int main() {
	int num,pos,res;
	string s;
	DoublyLL list;
	while(true){
		cout << "Enter an integer followed by the position at which to insert (0 to stop):";
		cin >> num >> pos;
		if (num == 0)
			break;
		res = list.insertAtPos(num, pos);
		if (res != -1)
			cout << "Element could not be inserted, valid positions [0-" << res << "]\n";
		else cout << num << " inserted\n";
		list.print();
	}
	cout << "Sum of elements:" << sum(list) << endl;
	cin.ignore();
	cout << "Enter a string:";
	//cin >> s;
	getline(cin, s);
	
	cout << s << endl;
	if (isPalindrome(s))
		cout << s << " is palindrome";
	else cout << s << " is not palindrome";
	return 0;
}