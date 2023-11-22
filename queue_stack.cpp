#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Queue {
private:
	stack<int> stack1;
	stack<int> stack2;

public:
	
	int dequeue() {
		if (stack1.empty()) {
			cout << "Queue is empty." << endl;
			return -1;
		}
		int data = stack1.top();
		stack1.pop();
		return data;
	}

	bool isEmpty() {
		return stack1.empty();
	}
};

