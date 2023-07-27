#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        int n = s.size();
        stack<int> aux;
        while (n --> 0) {
            aux.push(s.top());
            s.pop();
        }

        s.push(x);

        while (!aux.empty()) {
            s.push(aux.top());
            aux.pop();
        }
    }
    
    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
private:
    stack<int> s;
};


int main() {
    MyQueue* q = new MyQueue();
    q->push(1);
    q->push(2);
    cout << q->pop() << endl;
    cout << q->pop() << endl;
}