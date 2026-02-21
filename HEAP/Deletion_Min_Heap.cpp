#include <iostream>
using namespace std;

class MinHeap
{
    int *arr;
    int size;
    int total_size;

public:
    MinHeap(int n)
    {
        arr = new int(n);
        size = 0;
        total_size = n;
    }

    //! function to insert into the heap
    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = value; // insert at the last position
        int index = size;
        size++;

        // Compare with parent and swap if parent > child
        while (index > 0 && arr[(index - 1) / 2] > arr[index])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted into the heap\n";
    }

    // ! Heapify function for MinHeap
    void Heapify(int index)
    {
        int smallest = index;
        int left = 2 * index + 1;  // left child
        int right = 2 * index + 2; // right child

        // Find the smallest among parent, left and right child and store in smallest variable

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        // If smallest is not the parent, swap and continue heapifying
        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            Heapify(smallest);
        }
    }
    // Delete function - deletes the root element and replaces it with last element
    void Delete()
    {
        if (size == 0)
        {
            cout << "Heap UnderFlow \n";
            return;
        }

        cout << arr[0] << " deleted from heap\n";
        arr[0] = arr[size - 1]; // replacing root with last element
        size--;

        if (size == 0)
            return;

        // restore minheap property
        Heapify(0);
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
    MinHeap H1(6);
    H1.insert(14);
    H1.insert(4);
    H1.insert(11);

    H1.Delete();

    H1.print();

    H1.insert(1);
    H1.insert(24);
    H1.insert(114);

    H1.Delete();
    H1.Delete();
    H1.Delete();

    H1.print();

    H1.Delete();
    H1.Delete();
    H1.Delete();

    H1.print();
}