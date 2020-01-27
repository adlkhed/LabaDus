#include <iostream>

void print (int arr [8][8]) {
    for (int x = 0; x < 8; x++) {
        bool hugh = 0;
        for(int y = 0; y < 8; y++) {
            if(arr[x][y] != 0) {
                hugh = 1;
                std::cout << arr[x][y] << " ";
            }
        }
        if(hugh)
        std::cout << "\n";
    }
    std::cout << "\n";
}

int main() {
    int matrice[8][8] {
            {10,5,6,5,4,4,5,5},
            {5,10,1,5,1,1,1,1},
            {6,1,10,1,1,3,2,1},
            {5,5,1,10,5,5,7,5},
            {4,1,1,5,10,3,2,5},
            {4,1,3,5,3,10,5,6},
            {5,1,2,7,2,5,10,1},
            {5,1,1,5,5,6,1,10},
    };

    int nums [8] {0};
    nums[0] = 0;
    int count = 1;
    int path(0);

    int min_num, min_el;

    while (count < 8) {
        min_num = 10;

        print(matrice);

        for (int x = 0; x < 8; x++) {
            if(matrice [nums[count-1]][x] <= min_num && matrice [nums[count-1]][x] != 0) {
                min_num = matrice [nums[count-1]][x];
                min_el = x;
            }
        }
        nums[count] = min_el;
        path += min_num;

        for (int x = 0; x < 8; x++) {
            matrice[nums[count-1]][x] = 0;
            matrice[x][nums[count-1]] = 0;
        }

        count++;
    }

    for (int i = 0; i < 8; i++) {
        std::cout << nums[i]+1 << "\t";
    }
