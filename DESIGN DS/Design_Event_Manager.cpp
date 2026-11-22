#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

// pq with lazy deletion

class EventManager {
public:
  // id -> priority
  unordered_map<int, int> m;
  priority_queue<P> pq;

  EventManager(vector<vector<int>> &events) {
    for (auto &e : events) {
      int id = e[0];
      int pr = e[1];
      m[id] = pr;
      pq.push({pr, -id});
    }
  }

  void updatePriority(int eventId, int newPriority) {
    m[eventId] = newPriority;
    pq.push({newPriority, -eventId});
  }

  int pollHighest() {

    while (!pq.empty()) {
      auto [pr, negId] = pq.top();
      int id = -negId;

      if (m.count(id) && m[id] == pr) {
        pq.pop();
        m.erase(id);
        return id;
      }

      // Delete stale entry
      pq.pop();
    }

    return -1;
  }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */