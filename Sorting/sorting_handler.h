#include <functional>
using namespace std;
/// @brief Read integer array of size n
/// @param n size of array
/// @return pointer to the array
int *readIntArray(int n);

int *randomArray(int n);

/// @brief
/// @param arr
/// @param n
/// @param sortFunc
/// @param algorithmName
void sort(int arr[], int n, const function<void(int *, int)> &sortFunc, const string &algorithmName);
void sort(int* arr, int low, int high, const function<void(int*, int, int)> &sortFunc, const string &algorithmName);