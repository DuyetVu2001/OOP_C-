#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <stack>

//class {
//
//public:
//	int size() {
//		
//		return ;
//	}
//	
//	bool empty() {
//		
//	}
//	
//	void push(int ) {
//		
//	}
//	
//	void pop() { //loai bo phan tu o dinh stack
//		
//	}
//	
//	void top() { // truy cap phan tu o dau stack
//		
//	}
//};

int main() {
	int i = 100;
	stack<int> st;
	st.push(i);
	
	cout << st.top();
	return 0;
}

