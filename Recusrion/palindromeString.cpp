#include<bits/stdc++.h>
using namespace std;
bool palindrome(const string &s, int start, int end){
    if(start >= end){
        return true;
    }
    if(s[start] != s[end]){
        return false;
    }
    return palindrome(s, start + 1, end - 1);
}
int main(){
    string s;
    cin >> s;
    if(palindrome(s, 0, s.size() - 1)){
        cout << "YES" << endl;
    }     else{
        cout << "NO" << endl;
    }
    return 0;
}
