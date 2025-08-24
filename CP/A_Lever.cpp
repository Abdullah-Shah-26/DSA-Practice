#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n ;
    cin>>n;
    vector<int>arr(n);
    vector<int>brr(n);

    for(int i = 0;i <n;i++)
    cin>>arr[i];

    for(int i = 0;i <n;i++)
    cin>>brr[i];
    
    int cnt =0;
    for(int i = 0;i <n;i++)
    {
        if(arr[i] > brr[i])
        {
            cnt+= arr[i]-brr[i];
        }
    }
    cout << cnt+1 <<endl;

    }
    return 0;
}