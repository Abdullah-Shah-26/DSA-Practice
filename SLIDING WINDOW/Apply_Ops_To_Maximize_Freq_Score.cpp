#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// TC = O(2N) | SC = O(N)

class Solution {
  public:
    int maxFrequencyScore(vector<int>& a, long long k) {
    int n = a.size();
    sort(a.begin(), a.end());

    vector<ll> pref(n + 1,0); // pref[r + 1] - pref[l]

    for(int i = 1; i <= n; i++){
      pref[i] = pref[i-1] + a[i-1];
    }

    int ans = 1;

    int l = 0;
    for(int r = 0; r < n; r++){
      int mid = (l + r)/2;

      while(l <= r){
        int mid = (l + r)/2;
        ll median = a[mid];

        // Left = l .... mid-1
        // Lsum = pref[mid-1] - (l > 0 ? pref[l-1] : 0)
        // Lcost = (median * Lsize) - Lsum
        int Lcnt = mid - l;
        ll Lsum = pref[mid] - pref[l];
        ll Lcost = median * Lcnt - Lsum;

        // Right = mid+1 .... r
        // Rsum = pref[r] - pref[mid]
        // Rcost = (Rsum) - (median * Rsize)
        int Rcnt = r - mid;
        ll Rsum = pref[r + 1] - pref[mid + 1];
        ll Rcost = Rsum - median * Rcnt;

        // Total Cost = Lcost + Rcost
        ll Tcost = Lcost + Rcost;

        if(Tcost <= k){
          break; // To avoid shrinking window since we want maxAns
        }
       // If the cost to increase freq of range of elements in l.....r   > k - shrink window       
        l++;
      }
      ans = max(ans, r - l + 1);
    }      

    return ans;
    }
};