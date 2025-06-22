#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    int n, l;
    cin>>n>>l;

    vector<int>posi(n);

    posi[0] =  0;
    for(int i = 0; i< n -1; i++)
    {
        int d;
        cin>>d;
        posi[i+1] = (posi[i] + d)%l;
    }

    if(l % 3 != 0)
    {
        cout<< 0<<endl;
        return 0;
    }

    vector<int>count(l, 0);

    for(int i = 0; i < n; i++)
    {
        count[posi[i]]++;
    }

    int d = l / 3;

    long long ans = 0;

    for(int q = 0; q < d; q++)
    {
    ans += (long long)count[q]* count[(q + d)% l] * count[(q + 2 * d)%l];
    }
    cout<<ans<<endl;
    return 0;

}