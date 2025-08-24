#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int a1,a2,b1,b2;
        cin >> a1 >> a2 >> b1 >> b2;

        int res = 0;

        // All possible games
        pair<int,int> sa[2] = {{a1,a2},{a2,a1}};
        pair<int,int> sb[2] = {{b1,b2},{b2,b1}};

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                int s=0, l=0;
                // Round 1
                if(sa[i].first > sb[j].first) s++;
                else if(sb[j].first > sa[i].first) l++;
                // Round 2
                if(sa[i].second > sb[j].second) s++;
                else if(sb[j].second > sa[i].second) l++;
                if(s>l) res++;
            }
        }

        cout << res << "\n";
    }

    return 0;
}
