/*
Q. Create a linked list with nodes having information about a student and perform
Insert a new node at specified position.
Delete of a node with the roll number of student specified.
Reversal of that linked list.

*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int roll_number;
    string name;
    Node* next;

    Node(int roll, string student_name) {
        roll_number = roll;
        name = student_name;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insert_at_position(int position, int roll_number, string name) {
        Node* new_node = new Node(roll_number, name);
        if (position == 0) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* temp = head;
            for (int i = 0; temp != nullptr && i < position - 1; i++) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                cout << "Position out of range!" << endl;
                return;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    void delete_by_roll_number(int roll_number) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->roll_number == roll_number) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->roll_number != roll_number) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void reverse_list() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Roll Number: " << temp->roll_number << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;
    int choice, roll_number, position;
    string name;
    cout << "\n1. Insert a student\n2. Delete a student\n3. Reverse the list\n4. Display the list\n5. Exit\n";
    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter roll number: ";
            cin >> roll_number;
            cout << "Enter name: ";
            cin >> name;
            list.insert_at_position(position, roll_number, name);
            break;

        case 2:
            cout << "Enter roll number: ";
            cin >> roll_number;
            list.delete_by_roll_number(roll_number);
            break;

        case 3:
            list.reverse_list();
            break;

        case 4:
            list.display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
