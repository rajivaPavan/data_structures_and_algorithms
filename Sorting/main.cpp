#include <iostream>
#include "sorting_handler.h"
#include "sort.h"

using namespace std;

int main() {
    // a code to create 5 random arrays of user defined size
    int sizes[5] = {5000,7500,10000,15000,20000};
    for (int size: sizes) {
        // input n numbers space separated
        int n = size;
        cout << "total elements in array: " << size << endl;
        int *rand = randomArray(n);

        sort(rand, 0, n - 1, Sort::recursiveQuickSort, "Recursive Quick Sort");
        sort(rand, 0, n - 1, Sort::iterativeQuickSort, "Iterative Quick Sort");
        cout << endl;
    }

    return 0;
}
