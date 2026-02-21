#include <bits/stdc++.h>
using namespace std;

//! Map The Array Values to Lower Range Values
//* TC = O(NLogN)
//* SC = O(N)

int main()
{
  vector<int> values = {100, 1000, 1000, 10000, 10000, 100000, 1000000};

  cout << "Before" << endl;
  for (auto &i : values)
  {
    cout << i << " ";
  }
  cout << endl;

  sort(values.begin(), values.end());
  map<int, int> m; //* Gives Compressed Value
  map<int, int> back; //* Gives Original Idx for  
  for (int i = 0; i < n; i++) 
  {  
    if (!m[values[i]])
    {
      m[values[i]] = idx;
      back[idx] = values[i];
      idx++;
    }
  }
  for (int i = 0; i < n; i++)
  {
    values[i] = m[values[i]];
  }
  cout << "After " << endl;
  for (auto &i : values)
  {
    cout << i << " ";
  }
  cout << endl;
  cout << "Elements in Map - Back" << endl;
  for (auto &it : back)
  {
    cout << it.first << " " << it.second << endl;
  }
}