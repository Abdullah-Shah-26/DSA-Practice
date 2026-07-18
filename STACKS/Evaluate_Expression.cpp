#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
  s += '+'; // dummy

  int ans = 0;
  int last = 0;
  int num = 0;
  char op = '+';

  for (char c : s) {
    if (isdigit(c)) {
      num = num * 10 + (c - '0');
      continue;
    }

    switch (op) {
    case '+':
      ans += num;
      last = num;
      break;

    case '-':
      ans -= num;
      last = -num;
      break;

    case '*':
      ans = ans - last + (last * num);
      last = last * num;
      break;

    case '/':
      ans = ans - last + (last / num);
      last = last / num;
      break;
    }

    op = c;
    num = 0;
  }

  return ans;
}

int main() {
  string s;
  cin >> s;

  string t;
  bool prevDigit = false;

  for (char c : s) {
    if (isdigit(c)) {
      t += c;
      prevDigit = true;
    } else if (c == '+' || c == '-' || c == '*' || c == '/') {
      t += c;
      prevDigit = false;
    } else { // letter
      if (!prevDigit)
        t += 1;
    }
  }

  cout << calculate(t) << endl;
}