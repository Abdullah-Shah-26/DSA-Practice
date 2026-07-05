#include <bits/stdc++.h>
using namespace std;

// "abba" -> "^#a#b#b#a#$"
// '^' and '$' are sentinels so we never go out of bounds.
// '#' lets us handle even & odd len palindromes together.

string transform(const string &s) {
  string t = "^";

  for (char ch : s) {
    t += '#';
    t += ch;
  }

  t += '$';

  return t;
}

vector<int> manacher(string s) {

  string t = transform(s);

  int n = t.size();

  vector<int> p(n, 0);

  int center = 0; // Center of rightmost pali found so far
  int right = 0;  // Right bound of that pali

  for (int i = 1; i < n - 1; i++) {
    int mirror = 2 * center - i;

    // If i lies inside cur pali 
    // We already know part of its ans

    if (i < right)
      p[i] = min(right - i, p[mirror]);

    // Can't extend past right as we haven't explored it yet

    while (t[i + p[i] + 1] == t[i - p[i] - 1])
      p[i]++;

    // If pali goes farther right
    // Update best window 

    if (i + p[i] > right) {
      center = i;
      right = i + p[i];
    }
  }

  return p;
}

int main() {
  string s;
  cin >> s;

  string t = transform(s);
  vector<int> p = manacher(s);

  cout << "Original : " << s << endl;
  cout << "Tranformed : " << t << endl;

  cout << "Radius Array : " << endl;

  for (int x : p)
    cout << x << " ";

  cout << endl;

  return 0;
}