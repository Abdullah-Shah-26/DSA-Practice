#include <bits/stdc++.h>
using namespace std;

//! Map The Array Values to Lower Range Values
//* TC = O(NLogN)
//* SC = O(N)

int main()
{
  int n = 7;
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

  int idx = 1;
  for (int i = 0; i < n; i++) 
  {  
    if (!m[values[i]])
    {
      m[values[i]] = idx;
      back[idx] = values[i];
      idx++;
    }
  }

  //! Rewriting original values with compressed values
  for (int i = 0; i < n; i++)
  {
    values[i] = m[values[i]];
  }

  cout << "After " << endl;

  //! Printing compressed values
  for (auto &i : values)
  {
    cout << i << " ";
  }
  cout << endl;
  
  //! Cordinate Compressed Value -> Original Value
  cout << "Elements in Map - Back" << endl;
  for (auto &it : back){
    cout << it.first << " " << it.second << endl;
  }
}