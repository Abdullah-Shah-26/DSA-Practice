#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<bool> squares(n, 0);
    vector<int> query(q);
    for (int i = 0; i < q; i++) {
        cin >> query[i];
    }
// O(N * q ) TLE 
    for (int i = 0; i < q; i++) {
        int Q = query[i] - 1;
        squares[Q] = !squares[Q];

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (squares[j] == 1 && (j == 0 || squares[j - 1] != 1))
                count++;
        }

        cout << count << endl;
    }

    return 0;
}
