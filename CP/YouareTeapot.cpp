#include<bits/stdc++.h>
#include<iostream>
using namespace std;    
string findt(const string &s)
{
    int n = s.size();
    int first =-1;
    int last = -1;

    for(int i = 0;i <n;i++)
    {
        if(s[i] == 't')
        {
            if(first == -1) first = i; // 1st occurence
            last = i;
        }
    }

        if(first== -1)
        return "";

        return s.substr(first, last - first + 1);

}



int main()
{
     string s;
     cin >> s;
    
     int n = s.size();
    int x = 0;

    string res = findt(s);
    int t = res.size();
    if(t >= 3)
    {
        for(char ch : res)
        {
            if(ch=='t') x++;
        }
        cout << fixed << setprecision(17) << (x-2)/(t-2) << endl;
    }
   
     else 
     cout << 0 << endl;

}