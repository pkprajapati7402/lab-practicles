#include <iostream>
using namespace std;

template <typename T>
class Compare {
private:
    T num1, num2;

public:
    // Constructor to initialize the numbers
    Compare(T a, T b) : num1(a), num2(b) {
        cout << "Constructor called! Numbers are initialized." << endl;
    }

    // Function to find the bigger number
    T getBigger() {
        return (num1 > num2) ? num1 : num2;
    }

    // Destructor
    ~Compare() {
        cout << "Destructor called! Object is being destroyed." << endl;
    }
};

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    Compare<int> intCompare(a, b);
    cout << "Bigger integer is: " << intCompare.getBigger() << endl;

    double x, y;
    cout << "Enter two floating-point numbers: ";
    cin >> x >> y;

    Compare<double> doubleCompare(x, y);
    cout << "Bigger floating-point number is: " << doubleCompare.getBigger() << endl;

    return 0;
}
