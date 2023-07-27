#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        const int size = q.size();
        for (int i = 0; i < size-1; i++) {
            int x = q.front();
            q.pop();
            q.push(x);
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

private:
    queue<int> q;
};