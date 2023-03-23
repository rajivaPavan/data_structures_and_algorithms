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

private:
    
    static int *merge(int *arr, int l1, int r1, int l2, int r2);

    virtual int partition(int arr[], int l, int r) = 0;
};