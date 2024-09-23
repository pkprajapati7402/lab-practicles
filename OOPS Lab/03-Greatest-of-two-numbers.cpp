#include <iostream>
using namespace std;

class B;
class A{
    private:
        int numA;
    public:
        A(int a): numA(a){}
        friend int great(A,B);
};
class B{
    private:
        int numB;
    public:
        B(int b): numB(b) {}
        friend int great(A,B);
};
int great(A obja, B objb){
    return (obja.numA > objb.numB) ? obja.numA : objb.numB;
}

int main(){
    A obja(15);
    B objb(24);
    int x,y;
    cout << "Greatest is: " << great(obja,objb) << endl;
    return 0;
}
