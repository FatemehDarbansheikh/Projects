#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Queue {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void enqueue(int data) {
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(data);
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    
    bool isEmpty() {
        return stack1.empty();
    }
};
