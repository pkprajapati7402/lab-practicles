#include <iostream>
using namespace std;

template <typename T>
T square(T num) {
    return num * num;
}

int main() {
    int intNum = 5;
    double doubleNum = 4.5;
    float floatNum = 3.2f;

    cout << "Square of int: " << square(intNum) << endl;
    cout << "Square of double: " << square(doubleNum) << endl;
    cout << "Square of float: " << square(floatNum) << endl;

    return 0;
}
