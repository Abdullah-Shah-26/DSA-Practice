int peakElement(vector<int> &arr)
{
    // Your code here'
    int st = 0, end = arr.size() - 1; // to handle edge case
    // if st = 0 end = arr.size() -1 ; if mid was st then (mid-1) will be out of bounds
    // if we do (mid + 1) and mid was end out of bounds

    while (st <= end)
    {
        int mid = end + (st - end) / 2; // handles edge case

        // Peak Element
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return mid;
        // move right
        else if (arr[mid] > arr[mid - 1])
            st = mid + 1;
        // arr[mid ] > arr[mid + 1]
        else
            end = mid - 1;
    }
    return -1;
}

