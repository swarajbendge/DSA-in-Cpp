#include <bits/stdc++.h>
using namespace std;

void print1toN(int n){
    if(n == 0) return;
    print1toN(n - 1);
    cout << n << " ";
}

void printNto1(int n){
    if(n == 0) return;
    cout << n << " ";
    printNto1(n - 1);
}

int main(){
    int n;
    cin >> n;

    cout << "1 to n: ";
    print1toN(n);
    cout << "\n";

    cout << "n to 1: ";
    printNto1(n);
    cout << "\n";

    return 0;
}
