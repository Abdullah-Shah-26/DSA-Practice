#include<iostream>
#include<vector>
using namespace std;
int main(){ //!BRUTE FORCE APPROACH { NOT MOST OPTIMED WAY}
 int n=5;
    int arr[5]={1,2,3,4,5};
    int maxSum = arr[0];

    for (int st=0; st<n; st++){
        int currSum=0;
        for (int end =st;end<n;end++){
            currSum+=arr[end];
            maxSum=max(currSum,maxSum);
}
    }
    cout << "max subarray sum ="<<maxSum<<endl;
    return 0;
}