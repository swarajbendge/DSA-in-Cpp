#include<bits/stdc++.h>
using namespace std;
class Stack {
private: 
    int topIndex;
    int arr[100];
    int capacity;

public:
    Stack(int size){
        capacity = size;
        topIndex = -1;
    }

    void push(int value){
        if(isFull()){
            cout << " stack is full" << endl;
            return ;
        }
        arr[++topIndex] = value;
        cout << value << " Pushed into the stack" << endl;
    }

    void pop(){
        if(isEmpty()){
            cout << " UndrrFlow : stack is empty" << endl;
            return ;
        }
        cout << arr[topIndex--] << " element popped out of the stack" << endl;
    }
    
    int top(){
        if(isEmpty()){
            cout << "stack is empty" << endl;
            return -1;
        }
        return arr[topIndex];
    }
    
    bool isEmpty(){
        return topIndex == -1;
    }

    bool isFull(){
        return topIndex == capacity - 1;
    }

    void Display(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return ;
        }
        cout << "Stack elemens are : ";
        for(int i = 0; i <= topIndex; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }
};
int main(){
    Stack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    cout <<"top element is : " << st.top() << endl;
    st.Display();
    st.push(10);
    cout <<"top element is: " << st.top() << endl;
    st.pop();
    st.Display();

    return 0;
}
