// EXPERIMENT- 5
//  5. Implement two stacks in a single array.
#include <iostream>
using namespace std;
class TwoStacks
{
private:
    int *arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }
    void push1(int value)
    {
        if (top1 < top2 - 1)
        {
            arr[++top1] = value;
            INPUT
            cout << "Pushed " << value << " into Stack 1" << endl;
        }
        else
        {
            cout << "Stack Overflow! Cannot push into Stack 1." << endl;
        }
    }
    void push2(int value)
    {
        if (top1 < top2 - 1)
        {
            arr[--top2] = value;
            cout << "Pushed " << "value into Stack 2" << endl;
        }
        else
        {
            cout << "Stack Overflow! Cannot push into Stack 2." << endl;
        }
    }
    int pop1()
    {
        if (top1 >= 0)
        {
            int value = arr[top1--];
            return value;
        }
        else
        {
            cout << "Stack Underflow! Stack 1 is empty." << endl;
            return -1;
        }
    }
    int pop2()
    {
        if (top2 < size)
        {
            int value = arr[top2++];
            return value;
        }
        else
        {
            cout << "Stack Underflow! Stack 2 is empty." << endl;
            return -1;
        }
    }
    ~TwoStacks()
    {
        delete[] arr;
    }
};
int main()
{
    TwoStacks ts(10);
    ts.push1(10);
    ts.push1(20);
    ts.push1(30);
    ts.push2(100);
    ts.push2(200);
    ts.push2(300);
    cout << "Popped from Stack 1: " << ts.pop1() << endl;
    cout << "Popped from Stack 1: " << ts.pop1() << endl;
    cout << "Popped from Stack 2: " << ts.pop2() << endl;
    cout << "Popped from Stack 2: " << ts.pop2() << endl;
    return 0;
}
