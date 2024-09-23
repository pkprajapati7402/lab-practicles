#include <iostream>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    Complex(){
        real = 0;
        imag = 0;
    }
    Complex(float value){
        real = value;
        imag = value;
    }
    Complex(float r, float i){
        real = r;
        imag = i;
    }
    Complex add(Complex c){
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1;
    cout << "Complex number c1: ";
    c1.display();

    Complex c2(3.5);
    cout << "Complex number c2: ";
    c2.display();

    Complex c3(2.5, 4.5);
    cout << "Complex number c3: ";
    c3.display();

    Complex c4 = c2.add(c3);
    cout << "Sum of c2 and c3: ";
    c4.display();

    return 0;
}
