#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

struct node {
	int data;
	node *next;
};

int main() {
	node *head = new node();
	head->data = 1;
	head->next = NULL;
	
	cout << "ads" << head->data << endl;
	
	node *second = new node();
	second->data = 2;
	second->next = NULL;
	
	node *third = new node();
	third->data = 3;
	third->next = NULL;
	
	head->next = second;
	second->next =third;
	//
	int data = head->data;
	
	node *p = head;
	
	while (p != NULL) {
		data = p->data;
		p = p->next;
		
		cout << data << "->";
	}
	return 0;
}

