#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Node {
public:
	int data;
	Node *next;
};

class LinkedList {
public:
	int count;
	Node *head;
	
	bool isEmpty () {
		return (count != 0);
	}
	
	Node pop (int data) {
		Node *p = new Node();
		p->data = data;
		p = head;
		p->next = NULL;
		return *p;
	}
};

int main() {
	LinkedList l;
	cout << l->;
	return 0;
}

