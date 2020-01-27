#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, r,R[100];
    cout << "enter last element: ";
    cin >> n;
    cout << "enter number of elements you want: ";
    cin >> r;
    ofstream res;
    res.open ("results.txt", ios::out | ios::trunc);
    r--;
    for (int i = 0;i < 100;i++) {
        R[i] = 1;
    }
    while(R[0] != n + 1){
        for (int i = 0;i < r+1;i++) {
            res << R[i] << " ";
            cout << R[i] << " ";
        }
        res << endl;
        cout << endl;
        R[r]++;
        for (int i = r;i > 0; i--) {
            if(R[i] > n){
                R[i] = 1;
                R[i-1] = R[i-1] + 1;
            }
        }
    }
}
