#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

const int q = 11;
int BuildTrees(int n, int A[q][q]);
void DeleteDuplicates(int n, int A[q][q]);
int InDifferTrees(int n, int A[q][q], int first, int second);
void AddToTheTree(int n, int A[q][q], int first, int second);

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int A[11][11] =
            { 0, 2, 5, 7, 0, 0, 0, 0, 0, 0, 0,
              2, 0, 0, 0, 7, 0, 7, 0, 0, 0, 0,
              5, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0,
              7, 0, 0, 0, 0, 3, 1, 0, 0, 0, 0,
              0, 7, 5, 0, 0, 0, 0, 4, 1, 0, 0,
              0, 0, 4, 3, 0, 0, 0, 4, 0, 2, 0,
              0, 7, 0, 1, 0, 0, 0, 0, 3, 2, 0,
              0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 3,
              0, 0, 0, 0, 1, 0, 3, 0, 0, 0, 6,
              0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 4,
              0, 0, 0, 0, 0, 0, 0, 3, 6, 4, 0 };

    DeleteDuplicates(11, A);
    for (int i = 1; i <= 7; i++){
        cout << "\nВузли з вагою: " << i << ": ";
        for (int j = 1; j <= 11; j++){
            for (int k = 1; k <= 11; k++){
                if (A[j - 1][k - 1] == i){
                    cout << " " << j << "-" << k;;
                }
            }
        }
    }
    cout << "\n";

    int B[11][11];
    BuildTrees(11, B);
    cout << "\n\nНове дерево: ";//вага 7 - максимальна вага
    for (int i = 1; i <= 7; i++){
        //перший вузол
        for (int j = 1; j <= 11; j++){
            //другий вузол
            for (int k = 1; k <= 11; k++){
                if (A[j - 1][k - 1] == i && InDifferTrees(11, B, j, k)){
                    AddToTheTree(11, B, j, k);
                    cout << " " << j << "-" << k;
                }
            }
        }
    }
    return 0;
}

void DeleteDuplicates(int n, int A[q][q]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                A[i][j] = 0;
            }
        }
    }
}

int BuildTrees(int n, int A[q][q]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        A[i][i] = i + 1;
    }
    return A[n][n];
}
//Перевірте відсортовані вузли та додайте до дерева

void AddToTheTree(int n, int A[q][q], int first, int second) {
    int scndLine;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == second) {
                scndLine = i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == first) {
                for (int k = 0; k < n; k++) {
                    if (A[scndLine][k]) {
                        A[i][k] = A[scndLine][k];
                        A[scndLine][k] = 0;
                    }
                }
            }
        }
    }
}

int InDifferTrees(int n, int A[q][q], int first, int second){
    int temp1, temp2;
    //Лінія
    for (int i = 0; i < n; i++){
        temp1 = 0;
        temp2 = 0;
        //перший елемент
        for (int j = 0; j < n; j++){
            if (A[i][j] == first){
                temp1 = 1;
            }
        }
        //другий елемент
        for (int k = 0; k < n; k++){
            if (A[i][k] == second){
                temp2 = 1;
            }
        }
        if (temp1 && temp2){
            return 0;
        }
    }
    return 1;
}
