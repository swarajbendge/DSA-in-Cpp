#include<bits/stdc++.h>
using namespace std;
int power(int a, int b){
    if(b == 0) return 1;
    if(b % 2 == 0){
        int half = power(a, b/2);
        return half * half;
    } else{
        return a * power(a, b - 1);
    }
}
int main(){
    int a;
    cin >> a;
    int b;
    cin >> b;
    cout << power(a, b) << endl;
    return 0;
}
