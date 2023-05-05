#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left = 2*root + 1;
   int right = 2*root + 2;
   int larger = root;

   if(left < n && arr[left] > arr[larger])
      larger = left;
   
   if(right < n && arr[right] > arr[larger])
      larger = right;
   
   if(larger != root){
      swap(arr[root], arr[larger]);
      heapify(arr, n, larger);
   }
}

// function to build heap
void buildHeap(int arr[], int n)
{
   // build heapify
   for(int i= (int)n/2 - 1; i>=0; i--)
      heapify(arr, n, i);
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   buildHeap(arr, n);

   // extracting elements from heap one by one
   for(int i= n-1; i>0; i--){

      // exchange current root with last leaf
      swap(arr[0], arr[i]);
  
      // call min heapify on the to build new heap
      heapify(arr, i, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   // Taking input from user
   int n;
   cout << "Enter the array size:";
   cin >> n;
   int heap_arr[n];
   cout << "Enter the array elements:";
   for(int i=0; i<n; i++)
      cin >> heap_arr[i];
   cout << endl;
  
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
