#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
static const int MOD = 1e9 + 7;

inline void fastio() { ios::sync_with_stdio(false); cin.tie(nullptr); }

class MedianFinder {
public:
    priority_queue<int> leftMaxHeap; // smaller Half
    priority_queue<int, vector<int>, greater<int>> rightMinHeap; // larger Half 
    MedianFinder() {
        
    }
    
    void addNum(int num) {  // O(LogN)
        if(leftMaxHeap.empty() || (num <= leftMaxHeap.top())){
          leftMaxHeap.push(num);
        }
        else{
          rightMinHeap.push(num);
        }

        // Maintain condition
        if(abs((int)leftMaxHeap.size() - (int)rightMinHeap.size()) > 1){
          rightMinHeap.push(leftMaxHeap.top());
          leftMaxHeap.pop();
        }
        else if(leftMaxHeap.size() < rightMinHeap.size()){
          leftMaxHeap.push(rightMinHeap.top());
          rightMinHeap.pop();
        }
    }
    
    double findMedian() { // O(1)
        if(leftMaxHeap.size() == rightMinHeap.size()){
          double mean = (leftMaxHeap.top() + rightMinHeap.top())/2.0;
          return mean;
        }

        return leftMaxHeap.top();
    }
};