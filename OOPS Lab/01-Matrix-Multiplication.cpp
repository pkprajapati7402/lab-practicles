
#include <iostream>
using namespace std;
class matrix{
    private:
        int r1,r2,c1,c2;
    public:
        void inputArr(){
            cout << "Enter Row & Columns of Matrix 1: "; 
            cin >> r1 >> c1;
            cout << "Enter Row & Columns of Matrix 2: ";
            cin >> r2 >> c2;
        }
        void multiply(){
            if(c1 != r2){
                cout << "Can't be Multiplied !";
                
            } else{
                int a[100][100], b[100][100];
                cout << "Enter elements of Matrix 1: ";
                for(int i = 0; i < r1; i++){
                    for(int j = 0; j < c1; j++){
                        cin >> a[i][j];
                    }
                }
                cout << "Enter elements of Matrix 2: ";
                for(int i = 0; i < r2; i++){
                    for(int j = 0; j < c2; j++){
                        cin >> b[i][j];
                    }
                }
                // Multiplying the Matrix and display.
                for(int i = 0; i < r1; i++){
                    for(int j = 0; j < c2; j++){
                        int res = 0;
                        for(int k = 0; k < r2; k++){
                            res += a[i][k] * a[k][j];
                        }
                        cout << res << " ";
                    }
                    cout << endl;
                }
            }
        }
};
int main(){
    matrix obj;
    obj.inputArr();
    obj.multiply();
    return 0;
}
