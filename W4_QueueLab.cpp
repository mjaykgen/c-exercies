#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void print(queue<int>q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}
queue<int> arrange(queue<int> q, int c) {
	queue<int> less, greater;
	while (!q.empty()) {
		if (q.front() < c)
			less.push(q.front());
		else if (q.front() > c)
			greater.push(q.front());
		q.pop();
	}
	less.push(c);
	while (!greater.empty()) {
		less.push(greater.front());
		greater.pop();
	}
	return less;
}
//or arrange using the same queue
void arrangeInPlace(queue<int>& q, int cutoff){
	queue<int> greater;
	int size= q.size();
	while(size >0){
		if(q.front() > cutoff)
			greater.push(q.front());
		else if(q.front() < cutoff)
			q.push(q.front()); // push to same queue
		q.pop();
	}
	//add cutoff to q that contains all less elements and copy back the ones in greater
	q.push(cutoff);
	while(!greater.empty()){
		q.push(greater.front());
		greater.pop();
	}
}
stack<int> toStack(queue<int> q) {
	//create 2 different stacks,
	//one temporary and the other will hold the final result
	stack<int> tmp, st;

	//fill the tmp stack with the elements in the queue,
   // they will be stored in reversed order
	while (!q.empty()) {
		tmp.push(q.front());
		q.pop();
	}
	//now pop all elements from tmp and push them in stack
	//they will have the same order as in the queue
	while (!tmp.empty()) {
		st.push(tmp.top());
		tmp.pop();
	}
	return st; 
}


int main() {
	int n, nb,c;
	queue<int>q;
	cout << "How many elements you'd like to enter?:";
	cin >> nb;
	cout << "Enter " << nb << " elements:";
	while (nb > 0) {
		cin >> n;
		q.push(n);
		nb--;
	}
	cout << "Enter the cutoff value:";
	cin >> c;
	q = arrange(q, c);
	print(q);
	//convert q toStack
	stack<int>s = toStack(q);
	cout << "\n\nAfter toStack:";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}