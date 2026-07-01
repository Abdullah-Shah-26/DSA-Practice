#include <bits/stdc++.h>
using namespace std;

//! creating max heap using step down approach TC = O(N) from array
// SC = O(logn) - recursion in heapify function can be made O(1) using loop
#include <iostream>
void Heapify(int arr[], int index, int n)
{
  int largest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  // largest among parent left and right is stored and if parent < child - swap
  if (left < n && arr[left] > arr[largest])
    // TODO: if (left < n && arr[left] < arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    // TODO: if (right < n && arr[right] < arr[largest]) - for mean heap
    largest = right;
  if (largest != index)
  {
    swap(arr[largest], arr[index]);
    Heapify(arr, n, largest);
  }
}
void BuildMaxHeap(int arr[], int n)
{
  // we will ignore all leaf nodes and start from first bottom most node having child
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    Heapify(arr, i, n);
  }
}
void printHeap(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int main()
{
  int arr[] = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
  BuildMaxHeap(arr, 10);
  printHeap(arr, 10);
}