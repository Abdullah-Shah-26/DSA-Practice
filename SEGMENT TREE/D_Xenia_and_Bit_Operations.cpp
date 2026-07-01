#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);

void build(int i, int l, int h, vector<int>&arr, vector<int>&seg, int orr)
{
  if (l == h)
  {
    seg[i] = arr[l];
    return;
  }
  int mid = (l + h) >> 1;
  build(2 * i + 1, l, mid, arr, seg, !orr);
  build(2 * i + 2, mid + 1, h, arr, seg, !orr);
  if (orr)
  {
    seg[i] = seg[2 * i + 1] | seg[2 * i + 2];
  }
  else
  {
    seg[i] = seg[2 * i + 1] ^ seg[2 * i + 2];
  }
}

void update(int idx, int l, int h, vector<int>&seg, int orr, int i, int val)
{
  if (l == h)
  {
    seg[idx] = val;
    return;
  }
  int mid = (l + h) >> 1;
  if (i <= mid)
    update(2 * idx + 1, l, mid, seg, !orr, i, val);
  else
    update(2 * idx + 2, mid + 1, h, seg, !orr, i, val);

  if (orr)
  {
    seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
  }
  else
  {
    seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
  }
}

void solve()
{
  int n,q;
  cin >> n >> q;
  int el = 1 << n;
 vector<int>arr(el), seg(4*el);
  for (int i = 0; i < el; i++)
    cin >> arr[i];
  
  if (n % 2 == 0)
    build(0, 0, el - 1, arr, seg, 0);
  else
    build(0, 0, el - 1, arr, seg, 1);

  while (q--)
  {
    int i, val;
    cin >> i >> val;
    i--;
    if((n&1) == 0)
    {
      update(0,0,el-1,seg,0,i,val);
    }
    else 
    {
      update(0,0,el-1,seg,1,i,val);
    }
    cout << seg[0] << endl;
  }
}

int main()
{
  fastio;
    solve();
  return 0;
}