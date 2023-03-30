#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int median(vector<int> arr);

vector<int> optimizedBubbleSort(vector<int> arr);

void printVector(vector<int> arr);

int main() {
    const int N = 7;
    int data[N] = {7, 33 , 42, 3, 21, 3213, 32};
    vector<int> stream;
    cout << "Sorted \t\t Median" << endl;
    for(int i = 0; i < N; i++){
        //add to stream
        stream.push_back(data[i]);

        // optimizedBubbleSort
        stream = optimizedBubbleSort(stream);
        // find median
        int m = median(stream);
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

vector<int> optimizedBubbleSort(vector<int> arr) {
    bool swapped = false;
    int n = arr.size();
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

    return arr;
}

int median(vector<int> arr) {
    return arr[arr.size()/2];
}
