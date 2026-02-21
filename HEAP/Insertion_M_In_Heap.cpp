#include <iostream>
using namespace std;

class MinHeap
{
    // implementiong using array
    int *arr;
    int size;       // curr size of heap
    int Total_size; // total size of arr _ max capacity of heap

public:
    MinHeap(int n)
    {
        arr = new int(n);
        size = 0;
        Total_size = n;
    }

    //! funciton to insert in heap
    void insert(int value)
    {
        // first check if heap size is available
        if (size == Total_size)
        {
            cout << "Heap overflow \n";
            return;
        }

        arr[size] = value; // insert from last
        int index = size;
        size++;

        // compare it with parent
        // if parent > child - SWAP
        while (index > 0 && arr[(index - 1) / 2] > arr[index])
        {
            swap(arr[(index - 1) / 2], arr[index]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted into the heap \n";
    }
    // ! print heap
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    MinHeap H1(4);

    H1.insert(4);
    H1.insert(10);
    H1.insert(20);
    H1.insert(5);

    H1.print();

    H1.insert(1);

    H1.print();
}