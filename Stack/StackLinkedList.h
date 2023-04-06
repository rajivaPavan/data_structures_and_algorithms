/*
* Implement a stack using linked lists
*/
#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
};

class StackLinkedList{
    private:
        StackNode *top;
        int size;

    public:
        StackLinkedList(){
            top = NULL;
            size = 0;
        }

        void push(int x){
            StackNode *temp = new StackNode;
            temp -> data = x;
            temp -> next = top;
            top = temp;
            size++;
        };

        int pop(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return NULL;
            }
            StackNode *temp = top;
            top = top -> next;
            int x = temp -> data;
            delete temp;
            size--;
            return x;
        };

        bool isEmpty(){
            return size == 0;
        };

        int getTop(){
            return top -> data;
        };

        void display(){
            StackNode *temp = top;
            while(temp != NULL){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        };
};