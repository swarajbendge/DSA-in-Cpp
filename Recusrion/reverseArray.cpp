#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int> &nums, int start, int end){
    if(start >= end){
        return;
    }
    swap(nums[start], nums[end]);
    reverse(nums, start+1, end-1);
}
int main(){
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    reverse(nums, 0, n - 1);
    for(int x : nums){
        cout << x << " ";
    }
    return 0;
}
