# ARRAY INITIALIZATION

1. Static array : int arr[5];  //declare size
                  int arr[5] = {1,2,3,4,5};  //initialization with elements

2. Dynamic array(using pointers) : int *arr = new int[5];


# ARRAY INSERTION

    #include <iostream>
    using namespace std;
    void insert(int arr[], int &n, int pos, int val) {
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        n++;
    }
    int main() {
        int arr[10] = {1, 2, 3, 4, 5};
        int n = 5;

        int pos = 2, val = 10;
        insert(arr, n, pos, val);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        return 0;
    }



# ARRAY DELETION

    #include <iostream>
    using namespace std;

    void remove(int arr[], int &n, int pos) {
        if (pos < 0 || pos >= n) {
            cout << "Invalid position!" << endl;
            return;
        }

        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
    
        n--;
    }

    int main() {
        int arr[10] = {1, 2, 3, 4, 5}; // Assume max size is 10
        int n = 5;   // Current size

        int pos = 2;
        remove(arr, n, pos);

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        return 0;
    }  
