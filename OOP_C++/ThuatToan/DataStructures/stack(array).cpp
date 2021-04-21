#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

int current_size = -1;
const int MAX_SIZE = 100;
int stack[MAX_SIZE];

bool isEmpty() {
	return (current_size == -1);
}

bool isFull() {
	return (current_size == MAX_SIZE); 
}

void push(int data) {
	if (!isFull()) {
		current_size++;
		stack[current_size] = data;
	} else {
		cout << "Stack is full!" << endl;
	}
}

int top () {
	if (isEmpty()) {
		cout << "Stack is empty!";
	} else {
		int data = stack[current_size];
		return data;
	}
}

int pop () {
	if (isEmpty()) {
		cout << "Stack is empty!";
	} else {
		int data = stack[current_size];
		current_size--;
		return data;
	}
}

int main() {
	push(100);
	push(200);
	push(-300);
	cout << "TOP: " << top() << endl;
	pop();
	cout << "TOP: " << top() << endl;
	push(-300);
	
	while (!isEmpty()) {
		int data = pop();
		cout << data << " <-- ";
	}
	return 0;
}

