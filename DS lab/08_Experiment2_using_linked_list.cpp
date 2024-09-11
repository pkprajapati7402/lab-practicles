// EXPERIMENT- 8
//  8. Implement Experiment 2 Using Linked List.
//  INPUT
#include <iostream>
#include <string>
using namespace std;
struct Student
{
    int rollNo;
    string name;
    Student *next;
};
class StudentList
{
private:
    Student *head;

public:
    StudentList() : head(NULL) {}
    void insertStudent(int rollNo, string name, int position)
    {
        Student *newNode = new Student();
        newNode->rollNo = rollNo;
        newNode->name = name;
        newNode->next = NULL;
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Student *temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Position out of range!" << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void deleteStudentByRollNo(int rollNo)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->rollNo == rollNo)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
            cout << "Student with Roll No " << rollNo << " deleted." << endl;
            return;
        }
        Student *temp = head;
        while (temp->next != NULL && temp->next->rollNo != rollNo)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Student with Roll No " << rollNo << " not found." << endl;
            return;
        }
        Student *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        cout << "Student with Roll No " << rollNo << " deleted." << endl;
    }
    void reverseList()
    {
        Student *prev = NULL;
        Student *current = head;
        Student *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        cout << "List reversed." << endl;
    }
    void displayList()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }
        Student *temp = head;
        cout << "Student List:" << endl;
        while (temp != NULL)
        {
            cout << "Roll No: " << temp->rollNo << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    StudentList list;
    // Insert students
    list.insertStudent(101, "John", 1);
    list.insertStudent(102, "Alice", 2);
    list.insertStudent(103, "Bob", 3);
    list.insertStudent(104, "David", 2);
    // Display after insertion
    list.displayList();
    // Deleting student by roll number.
    list.deleteStudentByRollNo(102);
    list.displayList();
    list.reverseList();
    list.displayList();
    return 0;
}
