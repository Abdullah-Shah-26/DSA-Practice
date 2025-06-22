#include<bits/stdc++.h>
using namespace std;
int main(){
int n ;
cin>>n;


vector<int>arr(n-1);

for(int i = 0; i< n-1; i++)
{
    cin>> arr[i];
}

if(n == 2)
{
    cout << arr[0];
    return 0;
}

for(int i = 0; i< n-1;  i++)
{
    int sum = 0;

    for(int j = i; j < n-1; j++)
    {
        
        sum+= arr[j];
        cout << sum; 
        if (j != n - 2) cout << " ";
    }
cout <<endl;
}
return 0;

}
