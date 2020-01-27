#include <iostream>

using namespace std;

bool isUsed(int arr[], int size, int n) {
    bool t = 0;
    for (int x = 0; x < size; x++) {
        if (arr[x] == n)
            t = 1;
    }
    return t;
}

int main() {
    int vertices [8]{0};

    int buffer [8]{0};

    int c_a = 0;
    int c_b = 0;

    bool x[8][8] = {
            {0,1,1,0,0,0,0,0},
            {1,0,0,1,0,0,0,0},
            {1,0,0,1,0,0,0,0},
            {0,1,1,0,1,0,0,0},
            {0,0,0,1,0,1,0,1},
            {0,0,0,0,1,0,1,0},
            {0,0,0,0,0,1,0,0},
            {0,0,0,0,1,0,0,0}};

    bool add = 0;

    for (int a = 0; a < c_b+1; a++) {
        cout << buffer[a]+1 << " ";
    }
    cout << "\n";

    while(c_a < 7){
        add = 0;

        for(int i = 0; i < 8; i++) {
            if (x[buffer[c_b]][i] == 1 && !isUsed(vertices, 8, i)) {
                add = 1;
                vertices[++c_a] = i;
                buffer[++c_b] = i;
                for (int a = 0; a < c_b + 1; a++) {
                    cout << buffer[a] + 1 << " ";
                }
                cout << "\n";
                break;
            }
        }

        if (c_b != 0 && !add) {
            buffer[c_b--] = 0;

            for (int a = 0; a < c_b+1; a++) {
                cout << buffer[a]+1 << " ";
            }
            cout << "\n";
        }
    }

    while (c_b > 0){
        buffer[c_b--] = 0;

        for (int a = 0; a < c_b+1; a++) {
            cout << buffer[a]+1 << " ";
        }
        cout << "\n";
    }
}
