#include <iostream>

using namespace std;

int main()
{
    int n = 12;
    int N[12][12];
    for (int i = 0;i < 12;i++) {
        for (int j = 0;j < 12;j++) {
            N[i][j] = 0;
        }
        N[i][0] = 1;
    }
    for (int i = 1;i < 12;i++) {
        for (int j = 1;j < 11;j++) {
            N[i][j] = N[i-1][j] + N[i-1][j - 1];
        }
    }
    N[11][11] = 1;
    for (int i = 0;i < 12;i++) {
        cout << N[11][i] << " ";
    }
    cout << endl;
}
