#include <bits/stdc++.h>
using namespace std;

// TC = O(2N) + O(2N) 
// SC = O(N) + O(N)

class Solution {
  public:
    int n;
    using ll = long long;
    static const int MOD = 1e9 + 7;

    vector<int> getNSE(vector<int> &arr){
      vector<int> nse(n, n);
      stack<int> st;

      for(int i = n-1; i >= 0; i--){

        while(!st.empty() && arr[i] <= arr[st.top()]){
          st.pop();
        }

        nse[i] = st.empty() ? n : st.top();

        st.push(i);
      }

      return nse;
    }

    vector<int> getPSEE(vector<int> &arr){
      vector<int> psee(n, -1);
      stack<int> st;

      for(int i = 0; i < n; i++){

        while(!st.empty() && arr[i] < arr[st.top()]){
          st.pop();
        }

        psee[i] = st.empty() ? -1 : st.top();

        st.push(i);
      }

      return psee; // previous smaller or equal element's idx
    }

    int sumSubarrayMins(vector<int>& arr) {
    n = arr.size();

    vector<int> NSE = getNSE(arr);
    vector<int> PSEE = getPSEE(arr);

    ll ans = 0;

    for(int i = 0; i < n; i++){
      int l = i - PSEE[i];
      int r = NSE[i] - i;

      ans = (ans + (l * r * 1LL * arr[i]) % MOD) % MOD;
    }

    return ans;
    }
};