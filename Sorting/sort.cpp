#include "sort.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void swap(int *xp, int *yp);

void Sort::bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n; i++) // go through the array n times
    {
        for (int j = 0; j < n - 1; j++) // -1 because we are comparing j and j+1
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Sort::optimizedBubbleSort(int *arr, int n)
{
    // in this method we will stop the algorithm if the array is already sorted
    bool swapped = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void Sort::selectionSort(int *arr, int n)
{
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted sub-array
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void Sort::insertionSort(int *arr, int n)
{
    int i, j, min_idx;
    // One by one move boundary of
    // unsorted sub array
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

int *Sort::recursiveMergeSort(int *arr, int n)
{
    if (n == 1)
        return arr;
    int mid = (int)n / 2;
    int *left = recursiveMergeSort(arr, n);
    int left_n = mid;
    int *right = recursiveMergeSort(&arr[mid + 1], n);
    int right_n = n - mid;
    return merge(left, left_n, right, right_n);
}

int *Sort::iterativeMergeSort(int *arr, int n)
{
    int len = 1;
    while (len < n)
    {
        int i = 0;
        while (i < n)
        {
            int l1 = i;
            int r1 = i + len - 1;
            int l2 = i + len;
            int r2 = i + 2 * len - 1;
            if (l2 >= n)
                break;
            if (r2 >= n)
                r2 = n - 1;
            int* temp = merge(arr, l1, r1, l2, r2);
            for (int j = 0; j < r2 - l1 + 1; j++)
            {
                arr[i + j] = temp[j];
            }
            i = i + 2 * len;
        }
        len = 2 * len;
    }
    return arr;
}

int *Sort::recursiveQuickSort(int *arr, int low, int high)
{
    if(low < high){
        int partition_index  = partition(arr, low, high);
        recursiveQuickSort(arr, low, partition_index - 1);
        recursiveQuickSort(arr, partition_index + 1, high);
    }
    return arr;
}

int *Sort::iterativeQuickSort(int* arr, int low, int high)
{
    int n = high - low + 1;
    // Create an auxiliary stack
    int* stack = (int*)malloc(n * sizeof(int));

    // initialize top of stack
    int top = -1;

    // push initial values of low and high to stack
    stack[++top] = low;
    stack[++top] = high;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop high and low
        high = stack[top--];
        low = stack[top--];

        // Set pivot element at its correct position in sorted array
        int partition_index = partition(arr, low, high);

        // If there are elements on left side of pivot, then push left side to stack
        if (partition_index - 1 > low) {
            stack[++top] = low;
            stack[++top] = partition_index - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (partition_index + 1 < high) {
            stack[++top] = partition_index + 1;
            stack[++top] = high;
        }
    }
}

int *Sort::merge(int *arr, int l1, int r1, int l2, int r2)
{
    int *temp = (int *)malloc(sizeof(int) * (r2 - l1 + 1));
    int index = 0;
    while (l1 <= r1 && l2 <= r2)
    {
        if (arr[l1] <= arr[l2])
        {
            temp[index] = arr[l1];
            index++;
            l1++;
        }
        else
        {
            temp[index] = arr[l2];
            index++;
            l2++;
        }
    }
    while (l1 <= r1)
    {
        temp[index] = arr[l1];
        index++;
        l1++;
    }
    while (l2 <= r2)
    {
        temp[index] = arr[l2];
        index++;
        l2++;
    }
    return temp;
}

int* Sort::merge(int* left, int left_n, int* right, int right_n){
    //combine two arrays
    int* arr = (int*)malloc(sizeof(int)*(left_n+right_n));
    for(int i = 0; i<left_n;i++) arr[i] = left[i];
    for(int i = left_n; i<(left_n+right_n);i++) arr[i] = right[i-left_n];
    return merge(arr,0,left_n,0,right_n);
}

int Sort::partition(int arr[], int low, int high)
{
    // pivot (Element to be placed at right position)
    int pivot = arr[high];

    int i = (low -1);

    for(int j = low; j < high - 1; j++){

        // If current element is smaller than the pivot
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return (i + 1);
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printAlgorithmName(const string &name)
{
    cout << "Sorted using " << name << endl;
}

// Swap function
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to slice a given vector
// from range X to Y
vector<int> slicing(vector<int> &arr,
                    int X, int Y)
{

    // Starting and Ending iterators
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;

    // To store the sliced vector
    vector<int> result(Y - X + 1);

    // Copy vector using copy function()
    copy(start, end, result.begin());

    // Return the final sliced vector
    return result;
}