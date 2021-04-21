#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

struct Node {
	int data;
	Node* next;
};

Node* createNode(int init_data) {
	Node* node = new Node;
	node->data = init_data;
	node->next = NULL;
	return node;
}

struct LinkedList {
	Node* head;
	Node* tail;
};

void createList(LinkedList& l) {
	l.head = NULL;
	l.tail = NULL;
}

void addHead (LinkedList& l, Node* node) {
	if (l.head = NULL) {
		l.head = node;
		l.tail = node;
	} else {
		node->next = l.head;
		l.head = node;
	}
}

void addTail (LinkedList& l, Node* node) {
	if (l.head == NULL) {
		l.head = node;
		l.tail = node;
	} else {
		l.tail->next = node;
		l.tail = node;
	}
}

void insertAt (LinkedList& l, Node* node, int pos) {
	Node* temp = l.head;
	
	//1 phantu
	if (pos == 1) {
		addHead(l, node);
		return;
	}
	
	for (int i = 1; i < pos - 1; i++) {
		temp = temp->next;
	}
	
	if (temp != NULL) {
		node->next = temp->next;
		temp->next = node;
		if (temp == l.tail)
			l.tail = node;
	} else {
		cout << "\n Danh sach rong!\n";
	}
}

void removeHead (LinkedList& l) {
	if (l.head != NULL) {
		Node* tmp = l.head;
		l.head = tmp->next;
		delete tmp;
		
		if (l.head == NULL) {
			l.tail = NULL;
		}
		
		cout << "\nXoa dau danh sach thanh cong!\n";
		return;
	}
	cout << "\nXoa that bai! (Danh sach rong)\n";
}

void removeTail (LinkedList& l) {
	if (l.head != NULL) {
		if (l.head->next == NULL) {
			l.tail = NULL;
			delete l.head;
			l.head = NULL;
			cout << "\nXoa cuoi danh sach thanh cong!\n";
			return;
		}
		
		Node* tmp = l.head;	
		while (tmp->next->next != NULL) {
			tmp = tmp->next;
		}
		
		l.tail = tmp;
		delete tmp->next;
		
		cout << "\nXoa cuoi danh sach thanh cong!\n";
	}
	cout << "\nXoa that bai! (Danh sach rong)\n";
}

void removeAt (LinkedList& l, int pos) {
	if (l.head == NULL) {
		cout << "\nDanh sach rong!\n";
	}
	
	if (pos == 1) {
		removeHead(l);
		return;
	}
	
	int count = 0;
	Node* coutNode = l.head;
	while (coutNode != NULL) {
		coutNode = coutNode->next;
		count++;
	}
	
	if (pos < 1 || pos > count) {
		cout << "\n Vi tri khong hop le!\n";
		return;
	}
	
	Node* tmp = l.head;
	for (int i = 1; i < pos - 1; i++) {
		tmp = tmp->next;
	}
	
	if (tmp != NULL) {
		Node *tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
		
		if (tmp->next == NULL) {
			l.tail = tmp;
		}
		cout << "\nXoa tai vi tri thu " << pos << " thanh cong!\n";
	}	
}

void printList (LinkedList& l) {
	if (l.head != NULL) {
		Node* tmp = l.head;
		
		while (tmp != NULL) {
			cout << tmp->data << ' ';
			tmp = tmp->next;
		}
	}
}

int main() {
	LinkedList list;
	createList(list);
	
	for (int i = 0; i <= 5; i++) {
		addTail(list, createNode(i));
	}
	
	insertAt(list, createNode(10), 2);
	removeAt(list, 2);
	printList(list);
	return 0;
}
