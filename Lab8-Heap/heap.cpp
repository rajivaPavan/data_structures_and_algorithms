#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left = 2*root + 1;
   int right = 2*root + 2;

   // find greater element between left child and right child
   if(left < n && right < n){
      int greaterChild = arr[left] > arr[right] ? left : right;

      // if greater child is greater than root swap
      if(arr[greaterChild] > arr[root]){
         swap(arr[greaterChild], arr[root]);
         // call heapify on the greater child
         heapify(arr, n, greaterChild);
      }  
   } 
}

// function to build min heap
void buildHeap(int arr[], int n)
{
   // build heapify
   for(int i= (int)n/2 - 1; i>=0; i--)
      heapify(arr, n, i);
}
  
void displayArray(int arr[], int n);

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   buildHeap(arr, n);

   displayArray(arr, n);
  
   // extracting elements from heap one by one
   for(int i= n-1; i>0; i--){
      cout << "i = " << i << endl;
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
   // // Taking input from user
   // int n;
   // cout << "Enter the array size:";
   // cin >> n;
   // int heap_arr[n];
   // cout << "Enter the array elements:";
   // for(int i=0; i<n; i++)
   //    cin >> heap_arr[i];
   // cout << endl;

   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}