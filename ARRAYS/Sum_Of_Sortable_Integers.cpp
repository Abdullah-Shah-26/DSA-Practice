#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int sortableIntegers(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    for (int k = 1; k <= n; k++) {
      if (n % k != 0)
        continue;

      bool validK = true;
      int prevMax = -1e9; // Max of previous block must be < min of next block

      for (int i = 0; i < n; i += k) { // Iterating over all blocks of size k
        int curMin = 1e9;
        int curMax = -1e9;
        int rem = 0; // No of break points in our monotonicity can atmax be 1 so
                     // that it can be fixed via cyclic rotation

        for (int j = 0; j < k; j++) {
          curMin = min(curMin, nums[i + j]);
          curMax = max(curMax, nums[i + j]);

          if (j < k - 1 && nums[i + j] > nums[i + j + 1])
            rem++;
        }

        if (nums[i + k - 1] > nums[i])
          rem++;

        if (curMin < prevMax || rem > 1) {
          validK = false;
          break;
        }

        prevMax = curMax;
      }

      if (validK)
        ans += k;
    }

    return ans;
  }
};

// Using KMP
// TC = O(NLogN + N(sqrt(N)))

class Solution {
public:
  void computeLPS(vector<int> &p, vector<int> &LPS) {
    int n = p.size();

    for (int i = 1, j = 0; i < n;) {
      if (p[i] == p[j]) {
        LPS[i] = j + 1;
        i++;
        j++;
      } else {
        if (j == 0) {
          LPS[i] = 0;
          i++;
        } else
          j = LPS[j - 1];
      }
    }
  }

  bool KMP(vector<int> &pat, vector<int> &txt) {
    int n = txt.size();
    int m = pat.size();

    vector<int> LPS(m, 0);
    computeLPS(pat, LPS);

    int i = 0; // txt
    int j = 0; // pat

    while (i < n) {
      if (pat[j] == txt[i]) {
        i++;
        j++;
      }

      if (j == m) { // Found pat in text
        return true;
      } else if (i < n && pat[j] != txt[i]) {
        if (j != 0)
          j = LPS[j - 1];
        else
          i++;
      }
    }

    return false;
  }

  // If the unsorted part is substring of sorted+sorted str then rotation can
  // sort the array
  bool isRotationValid(vector<int> &v1, vector<int> &v2) {
    vector<int> text = v2;
    text.insert(end(text), begin(v2), end(v2));

    return KMP(v1, text);
  }

  int sortableIntegers(vector<int> &nums) {
    int n = nums.size();

    vector<int> sorted = nums;
    sort(begin(sorted), end(sorted));

    int sum = 0;

    for (int k = 1; k <= n; k++) {
      if (n % k != 0)
        continue;

      bool valid = true;

      for (int st = 0; st < n; st += k) {
        vector<int> v1(begin(nums) + st, begin(nums) + st + k);
        vector<int> v2(begin(sorted) + st, begin(sorted) + st + k);

        // If we are able to sort the array by rotating blocks of size k
        if (!isRotationValid(v1, v2)) {
          valid = false;
          break;
        }
      }

      if (valid)
        sum += k;
    }

    return sum;
  }
};