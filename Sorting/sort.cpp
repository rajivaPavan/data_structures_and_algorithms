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
    int *right = recursiveMergeSort(&arr[mid + 1], n);
    return arr;
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