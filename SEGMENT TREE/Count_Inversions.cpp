#include <bits/stdc++.h>
using namespace std;
class SGTree
{
  public:
  vector<int> seg;
  SGTree(int n)
  {
    seg.resize(4 * n + 1);
  }
  
  void build(int idx, int low, int high, int arr[])
  {
    if (low == high)
    {
      seg[idx] = arr[low];
      return;
    }
    int mid = (low + high) >> 1;
    build(2 * idx + 1, low, mid, arr);
    build(2 * idx + 2, mid + 1, high, arr);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
  }

  int query(int idx, int low, int high, int l, int r)
  {
    if (r < low || high < l)
      return 1e9;

    if (low >= l && high <= r)
      return seg[idx];

    int mid = (low + high) >> 1;
    return query(2 * idx + 1, low, mid, l, r) + query(2 * idx + 2, mid + 1, high, l, r);
  }
  void update(int idx, int low, int high, int i, int val)
  {
    if (low == high)
    {
      seg[idx] += val;
      return;
    }
    int mid = (low + high)>> 1;
    if(i <= mid)
    update(2*idx+1,low,mid,i,val);
    else 
    update(2*idx+2,mid+1,high,i,val);

    seg[idx] = seg[2*idx+1] + seg[2*idx+2];
  }
};

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    int arr[n];
    int mx = -1;
    for(int i = 0;i < n;i++)
    {
      cin >> arr[i];
      mx = max(mx, arr[i]);
    }
    mx += 1;
    int freq[mx] = {0};
    for(int i = 0;i < n ;i++)
    {
      freq[arr[i]]++;
    }
    SGTree st(mx);
    st.build(0,0,mx-1,freq);
    
    int cnt = 0;
    for(int i = 0;i < n;i++)
    {
      freq[arr[i]]--;
      st.update(0,0,mx-1,arr[i],-1);

      cnt += st.query(0,0,mx-1,1,arr[i]-1);
    }
    cout<< cnt << endl;
  }

int main() {
    fastio;
    solve();
    return 0;
}