#include <iostream>
#include <vector>
using namespace std;

class LIST {
public:
    virtual void store(int value) = 0;
    virtual int retrieve() = 0;
    virtual ~LIST() {}
};

class Stack : public LIST {
private:
    vector<int> stack;
public:
    void store(int value) override {
        stack.push_back(value);
    }

    int retrieve() override {
        if (!stack.empty()) {
            int value = stack.back();
            stack.pop_back();
            return value;
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }
};

class Queue : public LIST {
private:
    vector<int> queue;
public:
    void store(int value) override {
        queue.push_back(value);
    }

    int retrieve() override {
        if (!queue.empty()) {
            int value = queue.front();
            queue.erase(queue.begin());
            return value;
        } else {
            cout << "Queue is empty!" << endl;
            return -1;
        }
    }
};

int main() {
    LIST* listPtr;

    Stack s;
    listPtr = &s;
    listPtr->store(10);
    listPtr->store(20);
    listPtr->store(30);
    cout << "Stack retrieve: " << listPtr->retrieve() << endl;
    cout << "Stack retrieve: " << listPtr->retrieve() << endl;

    Queue q;
    listPtr = &q;
    listPtr->store(100);
    listPtr->store(200);
    listPtr->store(300);
    cout << "Queue retrieve: " << listPtr->retrieve() << endl;
    cout << "Queue retrieve: " << listPtr->retrieve() << endl;

    return 0;
}
