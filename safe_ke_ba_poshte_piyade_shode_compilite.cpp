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

    int dequeue() {
        if(stack1.empty()) {
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

//int main() {
//    Queue q;
//    q.enqueue(1);
//    q.enqueue(2);
//    q.enqueue(3);
//
//    cout << "Front element is: " << q.dequeue() << endl;
//    cout << "Front element is: " << q.dequeue() << endl;
//    cout << "Queue empty status: " << q.isEmpty() << endl;
//
//    return 0;
//}