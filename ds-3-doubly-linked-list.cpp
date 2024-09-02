// create doubly linked list with nodes having information about an employee and perform insettion at front of doubluy linked list and perofm deletion at end of that doubly linked list.
#include <iostream>
#include <string>
using namespace std;


struct Node
{
    string employeeName;
    int employeeID;
    Node* next;
    Node* prev;
};
class DoublyLinkedList{
    private:
    Node* head;
    Node* tail;
    public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void insertFront(const std::string& name, int id) {
        Node* newNode = new Node;
        newNode->employeeName = name;
        newNode->employeeID = id;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) { // If the list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void deleteEnd() {
        if (tail == nullptr) { // If the list is empty
            std::cout << "List is empty, nothing to delete." << std::endl;
            return;
        }

        Node* temp = tail;
        if (head == tail) { // If there's only one node
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << "Employee Name: " << temp->employeeName << ", Employee ID: " << temp->employeeID << std::endl;
            temp = temp->next;
        }
    }
};
int main(){
    DoublyLinkedList list;

    
    list.insertFront("Alice", 1);
    list.insertFront("Bob", 2);
    list.insertFront("Charlie", 3);

    cout << "List after inserting at the front:" << endl;
    list.printList();

    // Deleting nodes at the end
    list.deleteEnd();
    cout << "\nList after deleting at the end:" << endl;
    list.printList();

    // Additional deletions
    list.deleteEnd();
    list.deleteEnd();
    list.deleteEnd(); 

    cout << "\nList after deleting all nodes:" << endl;
    list.printList();

}
