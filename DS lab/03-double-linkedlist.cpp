/*
Q. Create a doubly linked list with nodes having information about an employee and perform insertion at front of doubly linked list and perform deletion at end of that doubly linked list.

*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int emp_id;
    string name;
    Node* prev;
    Node* next;

    Node(int id, string emp_name) {
        emp_id = id;
        name = emp_name;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Insert a new node at the front of the list
    void insert_at_front(int emp_id, string name) {
        Node* new_node = new Node(emp_id, name);

        if (head == nullptr) {
            head = tail = new_node; // List is empty
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }

        cout << "Employee inserted at the front: " << name << endl;
    }

    // Delete a node from the end of the list
    void delete_at_end() {
        if (tail == nullptr) {
            cout << "The list is empty, no deletion performed." << endl;
            return;
        }

        Node* temp = tail;
        if (head == tail) {
            // Only one node in the list
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        cout << "Employee deleted from the end: " << temp->name << endl;
        delete temp;
    }

    // Display the list from the front
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << "Employee ID: " << temp->emp_id << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    DoublyLinkedList list;
    int choice, emp_id;
    string name;

    while (true) {
        cout << "\n1. Insert employee at front\n2. Delete employee at end\n3. Display employees\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter employee ID: ";
            cin >> emp_id;
            cout << "Enter employee name: ";
            cin >> name;
            list.insert_at_front(emp_id, name);
            break;

        case 2:
            list.delete_at_end();
            break;

        case 3:
            list.display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
