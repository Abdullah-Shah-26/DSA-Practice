#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int score(vector<string> &cards, char x) {
    vector<int> left(10), right(10); // [x_, _x]
    int xxCnt = 0;                   // [xx]
    int L = 0, R = 0;

    for (string &s : cards) {
      if (s[0] == x && s[1] == x)
        xxCnt++;
      else if (s[0] == x) {
        left[s[1] - 'a']++;
        L++;
      } else if (s[1] == x) {
        right[s[0] - 'a']++;
        R++;
      }
    }

    int maxL = *max_element(begin(left), end(left));
    int maxR = *max_element(begin(right), end(right));

    // L = [ab, ab, ab, ac], No of pairL = 1 , i.e min(Lsize - maxFreqLeft,
    // Lsize/2)
    int pairL = min(L / 2, L - maxL);
    int pairR = min(R / 2, R - maxR);

    int rem = L - 2 * pairL;
    rem += R - 2 * pairR;

    int ans = pairL + pairR + min(xxCnt, rem);

    // pairsL = 3, pairsR = 2, remUnpaired = 2
    // XX = 10
    // (xx + unpaired) = 2, Now XX = 8
    // (xx + pairsL) = 3 pairs of L, Each of individual guy will form pair with
    // remXX
    //               = ()() ()() ()()

    //               = ()() ()() ()() ()() ()() ()()
    // Now XX = 8 - 6 = 2

    // (xx + piarsR) = 2 pairs of R, Each individual (a,b) guy will form pair
    // with remXX
    //               = ()()      ()()

    //               = ()() ()() ()()
    // Now XX = 2 - 2 = 0

    if (xxCnt > rem) {
      ans += min(pairL + pairR, (xxCnt - rem) / 2);
    }

    return ans;
  }
};