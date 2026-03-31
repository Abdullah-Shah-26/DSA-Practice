#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>bit;

//* TC = O(NlogN);
//* SC = O(N);


//! Wont work if arr[i] >= 10^6 so apply cordinate compression

void update(int id,int val)
{
  while(id <= n)
  {
    bit[id] += val;
    id += (id & -id);
  }
}

int query(int id)
{
  int ans = 0;
  while(id > 0)
  {
    ans += bit[id];
    id -= (id & -id);
  }
  return ans; 
}

int main()
{
  cin >> n;
  bit = vector<int>(n+1,0);
  vector<int>a(n+1);

  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
    update(i, a[i]); //! O(N Log N) Fenwick Build
  }

  int q;
  cin >> q;
  while(q--)
  {
    int typeOfQuery;
    cin >> typeOfQuery;

    //* L & R needs to be 1 based indexing 
    if(typeOfQuery == 1)
    {
      int L,R;
      cin >> L >> R;
      int ans = query(R) - query(L-1);
      cout << ans << endl;
    }
    else //* 
    {
      int id,val;
      cin >> id >> val;
      a[id] = val;
      update(id, -a[id]); 
    }
  }
}