#include <iostream>
#include <vector>

using namespace std;
double median(vector<int> arr);

vector<int> insertToSortedArray(vector<int> arr, int element);

void printVector(vector<int> arr);

int main() {
    const int N = 7;
    int data[N] = {7, 33 , 42, 3, 21, 3213, 32};
    vector<int> stream;
    cout << "Sorted \t\t Median" << endl;
    for(int i = 0; i < N; i++){
        // insertToSortedArray
        stream = insertToSortedArray(stream, data[i]);
        // find median
        double m = median(stream);
        printVector(stream);
        cout << "\t\t\t" << m << endl;
    }
    return 0;
}

void printVector(vector<int> arr) {
    cout <<"[";
    int n = arr.size();
    for(int i=0; i< n; i++){
        cout << arr[i];
        if(i < n -1) cout << ", ";
    }
    cout << "]";
}

vector<int> insertToSortedArray(vector<int> arr, int element) {
    int n = arr.size();
    if(n == 0) {
        arr.push_back(element);
        return arr;
    }
    int i = 0;
    while(i < n && arr[i] < element) i++;
    arr.insert(arr.begin() + i, element);
    return arr;
}

double median(vector<int> arr) {
    int n = arr.size();
    int mid = (int)(n-1)/2;
    if (n % 2 == 0) return (arr[mid] + arr[mid + 1]) / 2.0;
    return arr[mid];
}
