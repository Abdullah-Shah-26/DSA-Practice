#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >>t;
    while(t--)
    {
    int n;
     cin>>n;

        vector<int>arr(n);
        
        for(int i = 0; i< n; i++)
        cin>>arr[i];

      
//        vector<int>freq(n+1, 0);  .// failing for 5th bo

//     int maxi = 0;
//        for(int i = 0; i < n; i++)
//        {
//         freq[arr[i]]++;
//        }
//    int max_freq = 0;
//         for (int i = 1; i <= n; i++) {
//             max_freq = max(max_freq, freq[i]);
//         }
//     cout<< max_freq <<endl;   

        if(n ==1)
    {
        cout<< 1 <<endl;
        continue;
    }

    vector<int>last(n+1, -1);

    for(int i = 0; i < n ; i++)
{
    last[arr[i]] = i;
}
int segs = 1;
int i = 0;

while(i < n)
{
    int minlastoccur = n;
    set<int>s;
    for(int j = i; j < n; j++)
    {
        s.insert(arr[j]);
        minlastoccur = min(minlastoccur, last[arr[j]]);

        if(minlastoccur >= j + 1)
        {
            i = j + 1;
            segs++;
            break;
        }
    }
    if(minlastoccur <= i || i >=n) break;
}
cout<< segs<<endl;
    }
    return 0;
}