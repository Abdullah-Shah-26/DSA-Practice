#include <bits/stdc++.h>
using namespace std;

// TC = O(N * Range * LogN) + O(N log N)
// SC = O(Range)

#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> seg;

    SegTree(int n) {
        this->n = n;
        seg.assign(4 * n, 0);
    }

    // mark used time points
    void update(int idx, int nl, int nr, int pos) {
        if (nl == nr) {
            seg[idx] = 1;
            return;
        }

        int mid = (nl + nr) >> 1;

        if (pos <= mid)
            update(2*idx + 1, nl, mid, pos);
        else
            update(2*idx + 2, mid + 1, nr, pos);

        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }

    // count used time points in [ql, qr]
    int query(int idx, int nl, int nr, int ql, int qr) {
        if (nr < ql || nl > qr) return 0;

        if (nl >= ql && nr <= qr) return seg[idx];

        int mid = (nl + nr) >> 1;

        return query(2*idx + 1, nl, mid, ql, qr) +
               query(2*idx + 2, mid + 1, nr, ql, qr);
    }
};

class Solution {
  public:
  
  int findMinimumTime(vector<vector<int>>& tasks) {
      // sort by end
      sort(tasks.begin(), tasks.end(), 
            [](auto &a, auto &b) { return a[1] < b[1]; }); // O)


      int maxEnd = 0;
      for (auto &t : tasks) maxEnd = max(maxEnd, t[1]);

      SegTree st(maxEnd + 1);
      int ans = 0;

      for (auto &task : tasks) {
          int l = task[0];
          int r = task[1];
          int d = task[2];

          int have = st.query(0, 0, maxEnd, l, r);
          int need = d - have;

          for (int t = r; t >= l && need > 0; t--) {  // O(Range)
              if (st.query(0, 0, maxEnd, t, t) == 0) { // O(LogN)
                  st.update(0, 0, maxEnd, t);
                  ans++;
                  need--;
              }
          }
      }

      return ans;
  }
};