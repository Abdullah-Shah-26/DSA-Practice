#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
int t;
cin>>t;
while(t--)
{
    int n, q;
    cin>> n >> q;
    vector<int>arr(n);
    
    for(int i = 0; i< n; i++)
    {
        cin>>arr[i];
    }
long long score = 0;

for(int i =0; i<n-1; i++)
{
    score += min(arr[i], arr[i+1]);
}

while(q--)
{
    int i,x;
    cin>>i>>x;

    i--;

    if(i >0)
    {
        score-= min(arr[i-1],arr[i]);
        score+= min(arr[i-1],x);
    }
    if(i<n-1)
    {
        score-= min(arr[i], arr[i+1]);
        score+= min(x, arr[i+1]);
    }
arr[i]=x;
cout<<score<<endl;

}
}
return 0;
}