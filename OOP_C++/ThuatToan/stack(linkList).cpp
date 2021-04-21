#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

struct Node {
	int data;
	Node *next;
};

typedef struct Node *stack;

bool isEmpty (stack s) {
	return (s == NULL);
}

Node *createNode (int data) {
	Node *p = new Node();
	if (p == NULL) {
		return NULL;
	}
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
	if (!isEmpty(s)) {
		return s->data;
	}
	else {
		cout << "Stack is empty!" << endl;
	}
}

int pop (stack &s) {
	if (!isEmpty(s)) {
		int data = s->data;
		Node *x = s;
		s = s->next;
		delete(x);
		return data;
	}
	else {
		cout << "Stack is empty!" << endl;
	}
}

int main() {
	stack s;
	push(s, -2);
	push(s, 10);
	cout << pop(s);
	cout << "hsaf";
	cout << top(s);
	return 0;
}
