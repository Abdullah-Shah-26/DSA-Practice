#include<bits/stdc++.h>
using namespace std;
int main()
{

int t; 
cin>>t;

while(t--)
{
    int n, s;
    cin>>n>>s;

    if(n == 0)
    {
        cout<< 0<< endl;
         continue;
    }
    vector<int>arr(n);

    for(int i = 0; i< n; i++)
    cin>> arr[i];
    int count = 0;

    int l = arr[0], r = arr[n-1];
    count = r - l + min(abs(s - r), abs(s - l));
    cout<< count<<endl;

}

return 0;
}