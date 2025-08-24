#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int cnt = 0;
    int bar = arr[k-1]; // 0-index correction
    for(int i = 0; i < n; i++) {
        if(arr[i] >= bar && arr[i] > 0) cnt++; // positive score check
    }

    cout << cnt << endl;
    return 0;
}
