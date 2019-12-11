#include <stdio.h>
#include <iostream>
using namespace std;

int arrVal(int A[50]){
    int i,lenght;
    cout << "Enter array lenght" << endl;
    cin >> lenght;
    cout << "Enter " << lenght << " elements, any letter would be seen as zero" << endl;
    for (i = 0;i < lenght;i++) {
        cin >> A[i];
    }
    return lenght;
}

bool check(int A[50],int len){
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; j++){
            if (A[i] == A[j]){
                return 0;
            }
        }
    }
    return 1;
}

void output(int A[50]){
    int pr2 = 0;
    while((A[pr2] != 0) || (A[pr2 + 1] != 0)){
        cout << A[pr2] << "  ";
        pr2++;
    }
    cout << endl;
}

int counter (int C[50]){
    int pr2 = 0;
    while((C[pr2] != 0) || (C[pr2 + 1] != 0)){
        pr2++;
    }
    return pr2;
}

int main()
{

    int A[50],B[50],C[50],D[50];
    int a,pr1,pr2,i,lenghtA = 0,lenghtB = 0;
    for(i = 0; i <= 50; i++){
        A[i] = 0;
        B[i] = 0;
        C[i] = 0;
        D[i] = 0;
    }
    while (true){
        lenghtA = arrVal(A);
        lenghtB = arrVal(B);
        if ((check(A,lenghtA) == 1) && (check(B,lenghtB) == 1)){
            break;
        }
        cout << "You have entered doubling or inncorect vallues,try again" << endl;
    }
    //собсна перетин
    pr2 = 0;
    for(i = 0;i < lenghtA; i++){
        for (pr1 = 0;pr1 < lenghtB;pr1++) {
            if(A[i] == B[pr1]){
                C[pr2] = B[pr1];
                pr2++;
            }
        }
    }
    // вивеДиня
    cout << " Peretun " << endl;
    output(C);
    cout << "It's potyuzhnist is: " << counter(C) << endl;
    //собсна обиднана
    pr2 = 0;
    for (i = 0;i < lenghtA;i++) {
     D[i] = A[i];
    }
    pr2 = lenghtA;
    a = 1;
    for(i = 0;i < lenghtB; i++){
        for(pr1 = 0;pr1 < lenghtA;pr1++){
            if(B[i] == A[pr1])
            {
                a = 0;
            }
        }
        if(a == 1)
        {
            D[pr2] = B[i];
            pr2++;
        }
        a = 1;
   }
    // вивеДиня
    cout << " Obyednanya " << endl;
    output(D);
    cout << "It's potyuzhnist is: " << counter(D) << endl;

    return 0;
}
