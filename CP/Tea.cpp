#include <bits/stdc++.h>
using namespace std;

bool endsWithTea(const string &s) {
    if (s.size() < 3) return false;
    return s.compare(s.size() - 3, 3, "tea") == 0;
}

int main() {
    int n ;
    cin >> n;
    string s;
    cin >> s;

    if (endsWithTea(s))
        cout << "yes\n";
    else
        cout << "no\n";

    return 0;
}