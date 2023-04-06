#include <iostream>
#include "StackArray.h"
#include "StackLinkedList.h"
#include <chrono>
#include <functional>

using namespace std;
using namespace std::chrono;

// declare functions
void operateOnStack(void* stack, const string& stack_name, int* test_values);
void stackOperations(StackArray* stackPtr, int* test_values, int n);
void stackOperations(StackLinkedList* stackPtr, int* test_values, int n);
int *randomArray(int sz);

int main(){
    StackArray s1(20);
    StackLinkedList s2;
    int* random_test_values = randomArray(15);
    operateOnStack(&s1, "StackArray", random_test_values);
    operateOnStack(&s2, "StackLinkedList", random_test_values);
    return 0;
}

// pass stack by reference and do operations on it
// measure and display time taken
void operateOnStack(void* stack, const string& stack_name, int* test_values){

    // size of test values
    int n = sizeof(test_values) / sizeof(test_values[0]);

    //start timer
    auto start = high_resolution_clock::now();

    if(stack_name == "StackArray")
        stackOperations((StackArray*)stack, test_values, n);
    else if(stack_name == "StackLinkedList")
        stackOperations((StackLinkedList*)stack, test_values, n);
    else {
        cout << "Invalid stack name" << endl;
        return;
    }

    //stop timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken to do operations on " << stack_name << ": " << duration.count() << " ms" << endl;
}

void stackOperations(StackArray* stackPtr, int* test_values, int n){
    
    StackArray stack = *stackPtr;
    // push first 10 values
    for(int i = 0; i < 10; i++){
        stack.push(test_values[i]);
    }
    // display stack
    stack.display();
    // pop 5 values
    for(int i = 0; i < 5; i++){
        stack.pop();
    }
    // display stack
    stack.display();
    // push 4 values
    for(int i = 0; i < 4; i++){
        stack.push(test_values[i]);
    }
    // display stack
    stack.display();
}

void stackOperations(StackLinkedList* stackPtr, int* test_values, int n){
    StackLinkedList stack = *stackPtr;

    // push first 10 values
    for(int i = 0; i < 10; i++){
        stack.push(test_values[i]);
    }
    // display stack
    stack.display();
    // pop 5 values
    for(int i = 0; i < 5; i++){
        stack.pop();
    }
    // display stack
    stack.display();
    // push 4 values
    for(int i = 0; i < 4; i++){
        stack.push(test_values[i]);
    }
    // display stack
    stack.display();
}

int *randomArray(int sz)
{
    int *randArray = (int *)malloc(sizeof(int) * sz); // array of size n
    for (int i = 0; i < sz; i++)
        randArray[i] = rand() % 100; // Generate number between 0 to 99
    return randArray;
}