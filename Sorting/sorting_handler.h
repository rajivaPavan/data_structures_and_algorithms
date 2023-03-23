#include <functional>
#include <vector>

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
void sort(int arr[], int n, const std::function<void(int *, int)> &sortFunc, const std::string &algorithmName);

void sortVector(vector<int> arr, int n, const function<vector<int>(vector<int>, int)> &vectorSortFunc, const string &algorithmName);