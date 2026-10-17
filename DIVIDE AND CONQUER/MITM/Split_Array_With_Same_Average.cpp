/*
  sumA + sumB = S
  sumB = S - sumA

  sizeA + sizeB = N
  sizeB = N - sizeA

  sumA / sizeA = sumB / sizeB
  sumA / sizeA = (S - sumA) / (N - sizeA) [Cross multiply]
  sumA * (N - sizeA) = sizeA * (S - sumA)
  sumA * N - sizeA * sumA = sizeA * S - sizeA * sumA
  sumA * N = sizeA * S

  To split array with same avg, condition to be satisfied :
  sumA / sizeA = S / N

  Cannot use dfs + memo
  dfs(i, cnt, sum)

  = 30 * 30 * 1e4*30
  = 27 * 1e7
  = 2.7 * 1e8

  So we can select elements of A using MITM

  Both A and B must be non empty, means
  1 <= sizeA <= N - 1
*/

class Solution {
public:
  bool binarySearch(int rightSubSum, vector<int> &arr) {
    int low = 0;
    int high = (int)arr.size() - 1;

    while (low <= high) {
      int mid = (low + high) >> 1;

      if (arr[mid] == rightSubSum)
        return true;
      else if (arr[mid] > rightSubSum)
        high = mid - 1;
      else
        low = mid + 1;
    }

    return false;
  }

  bool splitArraySameAverage(vector<int> &nums) {
    int N = nums.size();
    int S = accumulate(begin(nums), end(nums), 0);

    int n1 = N / 2;
    int n2 = N - n1;

    // mp[size] -> {subsetSum1, subsetSum2, ...}
    unordered_map<int, vector<int>> sumsLeft;

    for (int mask = 0; mask < (1 << n1); mask++) {
      int s = 0;
      int cnt = 0;

      for (int i = 0; i < n1; i++) {
        if (mask & (1 << i)) {
          s += nums[i];
          cnt++;
        }
      }

      sumsLeft[cnt].push_back(s);
    }

    // mp[size] -> {subsetSum1, subsetSum2, ...}
    unordered_map<int, vector<int>> sumsRight;

    for (int mask = 0; mask < (1 << n2); mask++) {
      int s = 0;
      int cnt = 0;

      for (int i = 0; i < n2; i++) {
        if (mask & (1 << i)) {
          s += nums[i + n1];
          cnt++;
        }
      }

      sumsRight[cnt].push_back(s);
    }

    for (int cnt = 0; cnt <= n2; cnt++) {
      auto &v = sumsRight[cnt];
      sort(begin(v), end(v));
    }

    for (int l = 0; l <= n1; l++) {
      for (int leftSubSum : sumsLeft[l]) {

        for (int r = 0; r <= n2; r++) {
          int sizeA = l + r;

          // A and B both must be non empty
          if (sizeA == 0 || sizeA == N)
            continue;

          // sumA / sizeA = S / N
          // (leftSum + rightSum) / sizeA = S / N
          // rightSum = sizeA * S / N - leftSum

          if ((sizeA * S) % N != 0)
            continue;

          int rightSubSum = sizeA * S / N - leftSubSum;

          if (binarySearch(rightSubSum, sumsRight[r]))
            return true;
        }
      }
    }

    return false;
  }
};