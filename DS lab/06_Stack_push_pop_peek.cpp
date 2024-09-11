// EXPERIMENT- 6
//  6. Create a stack and perform Push, Pop, Peek and Traverse operations on the stack
//  using Linked List.
//  INPUT
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack() : top(NULL) {}
    void push(int value)
    {
        Node *newNode = newNode();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }
    int pop()
    {
        if (top == NULL)
            return -1;
        int value = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    int peek()
    {
        if (top == NULL)
            return -1;
        return top->data;
    }
    void traverse()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Stack stack;
    int n, a;
    cout << "Enter number of elements to be pushed: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        stack.push(a);
    }
    cout << "Top element is: " << stack.peek() << endl;
    stack.traverse();
    cout << "Elements after deleting: ";
    stack.pop();
    stack.traverse();
    return 0;
}
