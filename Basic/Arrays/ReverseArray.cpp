# There are different ways to reverse an array in C++ programming language.

1. Using swap keyword

// Time Complexity: O(N)
// Space Complexity: O(1)
  
void reverseArray(int arr[], int n){
  int start = 0;
  int end = n - 1;
  while(start < end){
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}


2. Using STL reverse function

// TC = O(N)
// SC = O(1)

void reverseArray(int arr[], int n){
  reverse(arr.begin(), arr.end());
}


3. Using extra space 

// TC = O(N)
// SC = O(N)

void reverseArray(int arr[], int n) {
    int newArr[n];
    for (int i = 0; i < n; i++) {
        newArr[i] = arr[n - i - 1];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = newArr[i];
    }
}


4. Using recursion

// TC = O(N)
// SC = O(N)

void reverseArray(int arr[], int left, int right) {
    if (left >= right) return;
    swap(arr[left], arr[right]);
    reverseArray(arr, left + 1, right - 1);
}
