#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
   

    int t;
    cin >> t;

    while(t--)
    {
        int n ,x ;
        cin>> n >> x;

        
    
        vector<int>arr(n);
        for(int i = 0; i< n; i++)
        cin>>arr[i];
// 0 - open // 1 - closed
        int f = -1, l = -1;

        for(int i = 0 ; i< n; i++)
        {
            if(arr[i] == 1)
            {
                if(f == -1)
                f = i; // 1st idx of 1 

                l= i; // last idx of 1
            }
        }
        if(l - f + 1 <= x)
        cout << "YES" <<endl;
        else 
        cout<<"NO"<<endl;

    }
return 0;
}