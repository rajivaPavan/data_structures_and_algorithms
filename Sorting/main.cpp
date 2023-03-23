#include <iostream>
#include <vector>
#include <iterator>
#include <chrono>
#include <functional>

using namespace std;
using namespace std::chrono;


int *randomArray(int sz)
{
    int *randArray = (int *)malloc(sizeof(int) * sz); // array of size n
    for (int i = 0; i < sz; i++)
        randArray[i] = rand() % 100; // Generate number between 0 to 99
    return randArray;
}

vector<int> merge(vector<int> left, vector<int> right);
vector<int> slicing(vector<int>& arr,
                    int X, int Y);

vector<int> recursiveMergeSort(vector<int> arr, int n)
{
    if(arr.size() == 1) return arr;
    int mid = arr.size()/2;
    vector<int> left = recursiveMergeSort(slicing(arr, 0, mid), n);
    vector<int> right = recursiveMergeSort(slicing(arr, mid+1, arr.size()-1), n);
    return merge(left, right);
}

vector<int> iterativeMergeSort(vector<int> arr, int n)
{
    int len = 1;
    while(len < n){
        int i  = 0;
        while(i<n){
            int l1 = i;
            int r1 = i + len -1;
            int l2 = i + len;
            int r2 = i +2 * len -1;
            if(l2 >= n) break;
            if(r2 >= n) r2 = n - 1;
            vector<int> temp = merge(slicing(arr, l1, r1), slicing(arr, l2, r2));
            for(int j = 0; j < r2 - l1 +1; j++){
                arr[i+j] = temp[j];
            }
            i = i + 2 * len;
        }
        len = 2 * len;
    }
    return arr;
}

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;
    while(left.size() > 0 && right.size() > 0){
        if(left[0] < right[0]){
            result.push_back(left[0]);
            left.erase(left.begin());
        }else{
            right.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    while(left.size()>0){
        result.push_back(left[0]);
        left.erase(left.begin());
    }
    while(right.size() > 0 ){
         right.push_back(right[0]);
         right.erase(right.begin());
    }
    return result;
}


int main()
{
    // a code to create 5 random arrays of user defined size
    int sizes[5] = {5000, 7500, 10000, 15000, 20000};
    for (int size : sizes)
    {
        // input n numbers space separated
        int n = size;
        cout << "total elements in array: " << size << endl;
        int *rand = randomArray(n);

        vector<int> arr;
        for(int i = 0; i < n; i++){
            arr.push_back(rand[i]);
        }

        vector<int> arr_copy(arr);

        // measure time taken to sort array
        auto start = high_resolution_clock::now();
        recursiveMergeSort(arr_copy, n);
        auto stop = high_resolution_clock::now();

        // print the time taken
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken: " << duration.count() << endl;


        // measure time taken to sort array
        auto start = high_resolution_clock::now();
        iterativeMergeSort(arr_copy, n);
        auto stop = high_resolution_clock::now();

        // print the time taken
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken: " << duration.count() << endl;

        cout<<endl;
    }
}


vector<int> slicing(vector<int>& arr,
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