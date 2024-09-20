#include <iostream>
#include <cmath>
using namespace std;

float stat(float x){
    return (pow(x, 3) - 4 * x - 9);
}

int main() {
    float a, b;
    int iter;
    
    cout << "Enter upper and lower limits: "; 
    cin >> a >> b;
    cout << "Enter number of iterations: "; 
    cin >> iter;
    
    if (stat(a) * stat(b) >= 0) {
        cout << "The function does not change sign in the given interval." << endl;
        return 1;
    }
    
    float mid;
    for (int i = 1; i <= iter; i++) {
        mid = (a + b) / 2;
        if (stat(mid) == 0.0) {
            break; // Exact root found
        } else if (stat(a) * stat(mid) < 0) {
            b = mid;
        } else {
            a = mid;
        }
    }
    
    cout << "Root is approximately: " << mid << endl;
    return 0;
}
