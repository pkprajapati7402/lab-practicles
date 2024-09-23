#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* str;
    int length;

public:
    MyString() : str(nullptr), length(0) {}

    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    ~MyString() {
        delete[] str;
    }

    MyString operator+(const MyString& s) {
        MyString temp;
        temp.length = length + s.length;
        temp.str = new char[temp.length + 1];
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }

    MyString& operator=(const MyString& s) {
        if (this != &s) {
            delete[] str;
            length = s.length;
            str = new char[length + 1];
            strcpy(str, s.str);
        }
        return *this;
    }

    bool operator<=(const MyString& s) {
        return strcmp(str, s.str) <= 0;
    }

    int getLength() const {
        return length;
    }

    void toLower() {
        for (int i = 0; i < length; ++i) {
            str[i] = tolower(str[i]);
        }
    }

    void toUpper() {
        for (int i = 0; i < length; ++i) {
            str[i] = toupper(str[i]);
        }
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    MyString s1("Etox");
    MyString s2("Krypto");

    MyString s3 = s1 + s2;
    cout << "Concatenated String: ";
    s3.display();

    MyString s4;
    s4 = s1;
    cout << "Copied String: ";
    s4.display();

    if (s1 <= s2)
        cout << "s1 is less than or equal to s2" << endl;
    else
        cout << "s1 is greater than s2" << endl;

    cout << "Length of s1: " << s1.getLength() << endl;

    s1.toLower();
    cout << "s1 in lowercase: ";
    s1.display();

    s2.toUpper();
    cout << "s2 in uppercase: ";
    s2.display();

    return 0;
}
