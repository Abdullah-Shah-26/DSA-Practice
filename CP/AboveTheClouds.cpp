#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n; 
        cin>> n;
        string s;
        cin>> s;

        if(n  < 3)
        {
            cout << "NO"<< endl;
            continue;
        }

        set<char>seen;

        for(char ch: s)
        {
            if(seen.count(ch))
            {
            cout<< "Yes"<<endl;
            continue;
            }
            seen.insert(ch);
        }
        cout<< "NO"<<endl;
    }
    return 0;
}