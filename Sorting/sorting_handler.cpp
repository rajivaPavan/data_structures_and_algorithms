#include <iostream>
#include "sorting_handler.h"
#include <iterator>
#include <chrono>
#include <functional>
#include <vector>

using namespace std;
using namespace std::chrono;

// declare private functions
void printArray(int *arr, int n);
void printAlgorithmName(const string &name);
int* makeArrayCopy(int* arr, int n);

void sort(int *arr, int n, const function<void(int *, int)>& sortFunc, const string &algorithmName)
{
    
    int *arr_copy = makeArrayCopy(arr, n);

    // measure time taken to sort array
    auto start = high_resolution_clock::now();
    sortFunc(arr_copy, n); // sort the new array
    auto stop = high_resolution_clock::now();

    printAlgorithmName(algorithmName);

    // print sorted array
    // printArray(arr_copy, n);

    // print the time taken
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << endl;
}

void sort(int arr[], int low, int high, const function<void(int *, int, int)> &sortFunc, const string &algorithmName)
{
    int n = high - low + 1;
    int *arr_copy = makeArrayCopy(arr, n);

    // measure time taken to sort array
    auto start = high_resolution_clock::now();
    sortFunc(arr_copy, low, high); // sort the new array
    auto stop = high_resolution_clock::now();

    printAlgorithmName(algorithmName);

//    printArray(arr_copy, n);

    // print the time taken
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << endl;
}

int *randomArray(int sz)
{
    int *randArray = (int *)malloc(sizeof(int) * sz); // array of size n
    for (int i = 0; i < sz; i++)
        randArray[i] = rand() % 100; // Generate number between 0 to 99
    return randArray;
}

int *readIntArray(int n)
{
    int *arr = (int *)malloc(sizeof(int) * n); // array of size n
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr + i);
    }
    return arr;
}


int *makeArrayCopy(int *arr, int n)
{
        // make copy of arr
    int *arr_copy = (int *)malloc(sizeof(int) * n);
    memcpy(arr_copy, arr, sizeof(int) * n);
    return arr_copy;
}