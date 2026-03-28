#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class Solution {
public:
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
    return !((e1[1] < e2[0]) || (e2[1] < e1[0]));
    }
};