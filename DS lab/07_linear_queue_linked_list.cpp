// EXPERIMENT- 7
//  7. Create a Linear Queue using Linked List and implement different operations such as
//  Insert, Delete, and Display the queue elements.
//  INPUT
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(NULL), rear(NULL) {}
    void enqueue(int value)
    {
        Node *newNode = newNode();
        newNode->data = value;
        newNode->next = NULL;
        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow! The queue is empty." << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
    }
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node *temp = front;
        cout << "Queue elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Queue()
    {
        while (front != NULL)
        {
            dequeue();
        }
    }
};
int main()
{
    Queue q;
    int choice, value;
    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
    return 0;
}
