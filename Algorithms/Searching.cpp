// Linear Search 

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "enter the size of array";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int toSearch;
    cout << "enter the element to search";
    cin >> toSearch;
    bool found = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == toSearch){
            cout << "element found at index " << i + 1 << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "element not found" << endl;
    }
    return 0;
}



// BINARY SEARCH //

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "enter the size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int toSearch;
    cout << "enter the element to search";
    cin >> toSearch;

    int start = 0;
    int end = n-1;
    bool found = false;

    sort(arr.begin(), arr.end());
    while(start <= end){
        int mid = start + (end - start) / 2;

        if(toSearch == arr[mid]){
            cout << "element found at: " << mid + 1;
            found = true;
            break;
        }
        else if (arr[mid] > toSearch){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    if(!found){
        cout << "element not found";
    }
    return 0;
}
