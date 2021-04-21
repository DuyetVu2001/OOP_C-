#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

struct Node {
	int data;
	Node *next;
};

typedef struct Node *stack;

bool isEmpty(stack s) {
	return (s == NULL);
}

Node *createNode(int data) {
	Node *p = new Node();
	p->data = data;
	p->next = NULL;
	
	return p;
}

void push (stack &s, int data) {
	Node *ptr = createNode(data);
	
	if (isEmpty(s)) {
		s = ptr;
	}
	else {
		ptr->next = s;
		s = ptr;
	}
}

int top (stack s) {
	if (isEmpty(s)) {
		cout << "Stack is empty!" << endl;
	} else {
		return s->data;
	}
}

int pop (stack &s) {
	if (isEmpty(s)) {
		cout << "Stack is empty!" << endl;
	} else {
		int data = s->data;
		Node *ptr = s;
		s = s->next;
		delete(ptr);
//		ptr->next = NULL;
		
		return data;
	}
}

int main() {
	stack s;
	push(s, 100);
	push(s, -99);
	push(s, 35);
	push(s, 811);
	
	cout << top(s) << endl;
	
	while (!isEmpty(s)) {
		int data = top(s);
		pop(s);
		cout << data << " <-- ";
	}
	return 0;
}

