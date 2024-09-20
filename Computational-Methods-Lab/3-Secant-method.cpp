#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * x - 4;  
}

double secantMethod(double x0, double x1, double tolerance, int maxIterations) {
    double x2;
    for (int i = 0; i < maxIterations; ++i) {
        double f0 = f(x0);
        double f1 = f(x1);

        // Avoid division by zero
        if (f1 - f0 == 0) {
            cout << "Division by zero encountered!" << endl;
            return NAN;
        }

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        if (fabs(x2 - x1) < tolerance) {
            cout << "Root found: " << setprecision(10) << x2 << endl;
            return x2;
        }

        x0 = x1;
        x1 = x2;
    }

    cout << "Max iterations reached. Last approximation: " << setprecision(10) << x2 << endl;
    return x2;
}

int main() {
    double x0, x1, tolerance;
    int maxIterations;

    cout << "Enter the first guess (x0): ";
    cin >> x0;
    cout << "Enter the second guess (x1): ";
    cin >> x1;
    cout << "Enter the tolerance: ";
    cin >> tolerance;
    cout << "Enter the maximum number of iterations: ";
    cin >> maxIterations;
    
    secantMethod(x0, x1, tolerance, maxIterations);

    return 0;
}
