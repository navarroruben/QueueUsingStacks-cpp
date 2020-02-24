// Ruben Navarro
// 02/24/2020
// Queue via Stacks
// A queue that operates using a pair of stacks while maintaining basic queue functionality.

#include <iostream>
#include <stack>

class MyQueue {
public:

    std::stack<int> s;
    std::stack<int> s2;

    MyQueue() {
    }

    // Push element x to the back of stack.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue and returns that element by swapping values in-between stacks
    int pop() {
        int n = 0;

        if (s.empty())
            return -1;

        if (s.size() == 1) {
            n = s.top();
            s.pop();
        }
        else if (s.size() > 1) {
            while (s.size() > 1) {
                s2.push(s.top());
                s.pop();
            }

            n = s.top();
            s.pop();

            while (!s2.empty()) {
                s.push(s2.top());
                s2.pop();
            }
        }
        return n;
    }

    // Get the front element (bottom of stack)
    int peek() {
        int n = 0;
        if (s.empty())
            return -1;

        if (s.size() == 1)
            return s.top();
        else if (s.size() > 1) {

            while (s.size() > 1) {
                s2.push(s.top());
                s.pop();
            }

            n = s.top();

            while (!s2.empty()) {
                s.push(s2.top());
                s2.pop();
            }
        }
            return n;
    }

    // Returns whether the queue is empty.
    bool empty() {
        if (s.empty())
            return true;
        else
            return false;
    }
};

int main() {

    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    std::cout << "Returning popped object: " << obj->pop() << std::endl;
    std::cout << "Returning popped object: " << obj->pop() << std::endl;

    return 0;
}
