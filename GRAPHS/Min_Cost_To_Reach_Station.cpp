#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;

bool canType(int x, vector<bool> &ok) {
  if (x == 0)
    return ok[0];

  while (x > 0) {
    if (!ok[x % 10])
      return false;

    x /= 10;
  }

  return true;
}

int digits(int x) {
  if (x == 0)
    return 1;

  int cnt = 0;

  while (x) {
    cnt++;
    x /= 10;
  }

  return cnt;
}

int main() {
  int n;
  cin >> n;

  int src, dest;
  cin >> src >> dest;

  int m;
  cin >> m;

  vector<bool> ok(10, false);

  for (int i = 0; i < m; i++) {
    int d;
    cin >> d;
    ok[d] = 1;
  }

  vector<pair<int, int>> typable;

  for (int station = 1; station <= n; station++) {
    if (canType(station, ok)) {
      typable.push_back({station, digits(station) + 1});
    }
  }

  vector<int> dist(n + 1, 1e9);
  priority_queue<P, vector<P>, greater<P>> pq;

  dist[src] = 0;
  pq.push({0, src});

  while (!pq.empty()) {
    auto [cost, cur] = pq.top();
    pq.pop();

    if (cost != dist[cur])
      continue;

    // Forward
    int nxt = (cur == n ? 1 : cur + 1);

    if (dist[nxt] > cost + 1) {
      dist[nxt] = cost + 1;
      pq.push({dist[nxt], nxt});
    }

    // Backward
    int prv = (cur == 1 ? n : cur - 1);

    if (dist[prv] > cost + 1) {
      dist[prv] = cost + 1;
      pq.push({dist[prv], prv});
    }

    // Type typeable stations
    for (auto [station, w] : typable) {
      if (dist[station] > cost + w) {
        dist[station] = cost + w;
        pq.push({dist[station], station});
      }
    }
  }

  cout << dist[dest] << '\n';

  return 0;
}
