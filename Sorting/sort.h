#include <functional>
#include <string>

class Sort
{
public:
    /// @brief Bubble sort is a sorting algorithm that repeatedly goes through the array
    /// and swaps adjacent elements if they are in the wrong order
    /// @param arr the array to be sorted
    /// @param n the size of the array
    static void bubbleSort(int *arr, int n);

    static void optimizedBubbleSort(int *arr, int n);
    static void selectionSort(int *arr, int n);
    static void insertionSort(int *arr, int n);
    static int* recursiveMergeSort(int* arr, int n);
    static int* iterativeMergeSort(int* arr, int n);
    static int* recursiveQuickSort(int* arr, int low, int high);
    static int* iterativeQuickSort(int* arr, int low, int high);

private:
    
    static int *merge(int *arr, int l1, int r1, int l2, int r2);
    static int *merge(int *left, int left_n, int *right, int right_n);

    static int partition(int arr[], int low, int high);
};