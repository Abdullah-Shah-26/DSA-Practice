#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
     int n ;
     cin>> n;

     vector<int>arr(n);

     for(int i = 0; i < n; i++)
     cin >> arr[i];

     sort(arr.rbegin(), arr.rend());

     int x = 0; 
     for(int i = 0; i < n;i++)
     {
    if(arr[i] >= i + 1)
    x = i + 1;
     }
     cout << x << endl;
     return 0;
}
