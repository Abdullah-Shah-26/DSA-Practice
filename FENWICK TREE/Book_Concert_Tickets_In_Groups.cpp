#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Fenwick{
public:
  int n;
  vector<ll> bit;

  Fenwick(int size){
    n = size;
    bit.resize(n + 1, 0);
  }

  void add(int i, ll val){
    i++;

    while(i <= n){
      bit[i] += val;
      i += (i & -i);
    }
  }

  ll sum(int i){
    i++;
    ll ans = 0;

    while(i > 0){
      ans += bit[i];
      i -= (i & -i);
    }
    return ans;
  }

  ll rangeSum(int l, int r){
    if(l > r) return 0;

    return sum(r) - (l ? sum(l - 1) : 0);
  }
};

class SegTree{
public:
  int n;

  // Stores max remaining seats
  vector<int> seg;

  SegTree(int size, int seats){
    n = size;

    seg.resize(4 * n);

    build(0, 0, n-1, seats);
  }

  void build(int i, int l, int r, int seats){
    if(l == r){ // Leaf Node - One row
      seg[i] = seats;
      return; 
    }

    int mid = (l + r) >> 1;

    build(2 * i + 1, l, mid, seats);
    build(2 * i + 2, mid + 1, r, seats);

    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
  }

  // Update remaining seats of one row
  void update(int i, int l, int r, int pos, int val){
    if(l == r){
      seg[i] = val;
      return;
    }

    int mid = (l + r) >> 1;

    if(pos <= mid)
      update(2 * i + 1, l, mid, pos, val);
    else
      update(2 * i + 2, mid + 1, r, pos, val);

    seg[i] = max(seg[2 * i + 1], seg[2 * i + 2]);
  }

  // Finding earliest row <= maxRow
  // Having remaining seats >= k
  int firstRow(int i, int l, int r, int k, int maxRow){
    if(l > maxRow)
      return -1;

    if(seg[i] < k)
      return -1;

    if(l == r)
      return l;

    int mid = (l + r) >> 1;

    int leftRes = firstRow(2 * i + 1, l, mid, k, maxRow);
    if(leftRes != -1)
      return leftRes;

    return firstRow(2 * i + 2, mid + 1, r, k, maxRow);
  }
};

class BookMyShow {
public:

  int n, m;

  // remaining[i] = seats left in row i
  vector<int> remaining;

  SegTree *st;
  Fenwick *ft;

  BookMyShow(int n, int m) {
    this->n = n;
    this->m = m;

    remaining.resize(n, m);

    // SegTree for max queries
    st = new SegTree(n, m);

    // Fenwick for prefSum
    ft = new Fenwick(n);

    // Initally all rows have m seats
    for(int i = 0; i < n; i++)
      ft->add(i, m);
  }
  
  vector<int> gather(int k, int maxRow) {
    // Finding earliest row having >= k seats
    int row = st->firstRow(0, 0, n-1, k, maxRow);

    if(row == -1)
      return {};

    // Seats are filled L -> R
    int startSeat = m - remaining[row];

    // Consume seats
    remaining[row] -= k;

    st->update(0, 0, n-1, row, remaining[row]);
    ft->add(row, -k);

    return {row, startSeat};
  }
  
  bool scatter(int k, int maxRow) {
    // Total seats available in rows [0...maxRow]
    ll totalSeats = ft->rangeSum(0, maxRow);

    if(totalSeats < k)
      return false;

    while(k > 0){
      // Finding 1st non-empty row
      int row = st->firstRow(0, 0, n-1, 1, maxRow);

      // Taking as many as possible
      int take = min(remaining[row], k);

      remaining[row] -= take;
      k -= take;

      st->update(0, 0, n-1, row, remaining[row]);
      ft->add(row, -take);
    }    

    return true;
  }
};
