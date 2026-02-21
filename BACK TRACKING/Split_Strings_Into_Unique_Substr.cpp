class Solution {
public:
    int maxi = 0;
    // TC = O(N * 2^N)
    // SC = O(N) + O(N)
    //      Rec + Set 
    void solve(int i, string &s, unordered_set<string>& st, int n) {
        // PRUNE
        if (st.size() + (n - i) <= maxi) return;

        if (i == n) {z
            maxi = max(maxi, (int)st.size());
            return;
        }

        for (int j = i; j < n; j++) {
            string word = s.substr(i, j - i + 1);
            if (!st.count(word)) {
                st.insert(word);
                solve(j + 1, s, st, n);
                st.erase(word);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        solve(0, s, st, s.size());
        return maxi;
    }
};