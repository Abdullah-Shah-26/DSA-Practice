#include <iostream>
using namespace std;

class MaxHeap
{
    // implementing using array
    int *arr;
    int size;       // current size of heap
    int total_size; // totol size of array - maximum capacity of heap

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    //! function to insert into the heap
    void insert(int value)
    {
        // check if heap size is available or not
        if (size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value; // insert from last
        int index = size;
        size++;

        // compare it with parent
        //  if parent < child swap
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted into the heap\n";
    }

    //! print heap
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    MaxHeap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);

    H1.print();

    H1.insert(114); 
    H1.insert(1);

    H1.print();
}
