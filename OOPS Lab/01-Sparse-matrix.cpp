// Q. Implement sparse matrix using arrays. Description of program:
// Read a 2D array from the user.
// Store it in the sparse matrix form, using an array of structures.
// Print the final Array.
// Input:


#include <iostream>
using namespace std;
int main(){
    int a[100][100], m, n, count = 0;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;
    cout << "Enter elements: ";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0){
                count++;
            }
        }
    }
    cout << "Here's your array \n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    (count > (m*n)/2)? cout << "It's sparse.": cout << "Not!";
}