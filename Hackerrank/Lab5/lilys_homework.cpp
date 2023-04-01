// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <fstream>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int partition_index = partition(arr, low, high);
        quickSort(arr, low, partition_index - 1);
        quickSort(arr, partition_index + 1, high);
    }
}

int binarySearch(vector<int>& arr, int element, int low, int high){
    if(low > high){
        return -1;
    }
    
    int mid = (low + high)/2;
    if(element == arr[mid]) 
        return mid;
    else if(element > arr[mid])
        return binarySearch(arr, element, mid + 1, high);
    else
        return binarySearch(arr, element, low, mid - 1);
}

/*
 * Complete the 'lilysHomework' function below.
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// Returns an unordered map with the sorted positions of each element in the array
unordered_map<int, pair<int, bool>> getSortedMap(vector<int> arr, vector<int>& sorted_arr){
    int arr_length = arr.size();

    // pair contains the sorted position and the flag for visited
    unordered_map<int, pair<int, bool>> sorted_position;
    // track where the elements have been sorted to in the ascending order 
    for(int i = 0; i < arr_length; i++){
        int element = arr[i];
        int sorted_index = binarySearch(sorted_arr, element, 0, arr_length);
        sorted_position[i] = {sorted_index, false};
    }

    return sorted_position;
}

// Returns the minimum number of swaps needed to sort the array
int calculateSwaps(unordered_map<int, pair<int, bool>> sorted_map){
    int swaps = 0;
    
    for(auto x : sorted_map){
        int index = x.first;
        bool visited = sorted_map[index].second;
        
        while(!visited){
            sorted_map[index].second = true;
            int next = sorted_map[index].first;
            // if the next index is the same as the current index, there's no need to swap
            if(next == index) 
                break;
            index = next;
            visited = sorted_map[next].second; // check if the next index has been visited
            if(!visited) swaps++;
        }
    }
    return swaps;
}

// Updates the sorted positions to their reverse order
void reverseSortedMap(unordered_map<int, pair<int, bool>>& sorted_map, int count){
    // find the sorted position of each element in the reverse order by subtracting the initial sorted position from the last index
    int last = (count - 1);
    for(int i =0; i< count; i++){
        sorted_map[i].first = last - sorted_map[i].first;
    }
}

int lilysHomework(vector<int> arr){
    int arr_length = arr.size();
    
    // Create a copy of the array and sort it in ascending order
    vector<int> arr_copy(arr);
    quickSort(arr_copy, 0, arr_length - 1);    
    
    // Get sorted positions of each element in the sorted array(in the ascending order)
    unordered_map<int, pair<int, bool>> sorted_map =  getSortedMap(arr, arr_copy);
        
    // Calculate the minimum number of swaps needed to sort the array in ascending order
    int swaps_a = calculateSwaps(sorted_map);
    
    // Get sorted positions of each element in the sorted array(in the descending order)
    reverseSortedMap(sorted_map, arr_length);
    
    // Calculate the minimum number of swaps needed to sort the array in descending order
    int swaps_b = calculateSwaps(sorted_map);
    
    return min(swaps_a, swaps_b);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int c) { return !isspace(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](int c) { return !isspace(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}