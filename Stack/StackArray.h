/*
* Implementation of a stack using an array
*/

#include <iostream>
using namespace std;

class StackArray{
    private:
        int *stack;
        int top;
        int size;
        int max_size;

    public:
        StackArray(int max_size){
            this -> max_size = max_size;
            stack = new int[max_size];
            size = 0;
            top = -1;
        };

        void push(int x){
            if(isFull()){
                cout << "Stack Overflow" << endl;
                return;
            }
            stack[++top] = x;
            size++;
        };

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return -1;
            }
            size--;
            return stack[top--];
        };

        int getTop(){
            return stack[top];
        };

        bool isEmpty(){
            return size == 0;
        };

        bool isFull(){
            return size == max_size;
        };

        void display(){
            // loop end to start
            for(int i = top; i >= 0; i--){
                cout << stack[i] << " ";
            }
            cout << endl;
        };
};
