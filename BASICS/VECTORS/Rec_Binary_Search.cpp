#include <iostream>
#include <vector>
using namespace std;

int RecBinarySearch(vector<int> arr, int tar, int st, int end) {
    if (st <= end) {
        int mid = st + (end - st) / 2;
        if (tar > arr[mid]) {
            return RecBinarySearch(arr, tar, mid + 1, end);
        } else if (tar < arr[mid]) {
            return RecBinarySearch(arr, tar, st, mid - 1);
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};
    int tar1 = 4;
    cout << RecBinarySearch(arr1, tar1, 0, arr1.size() - 1) << endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};
    int tar2 = 10;
    cout << RecBinarySearch(arr2, tar2, 0, arr2.size() - 1) << endl;
    
    return 0;
}
  