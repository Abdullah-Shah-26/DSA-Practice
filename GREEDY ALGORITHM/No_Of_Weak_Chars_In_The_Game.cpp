#include <bits/stdc++.h>
using namespace std;

// TC = O(N Log N) | SC = O(1)

class Solution {
  public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {

    // Smaller attack first
    // If same attack -> Better defense first

    sort(begin(p), end(p), [](auto &x, auto &y){
      if(x[0] == y[0]) return x[1] > y[1];
      
      return x[0] < y[0]; 
    });     

    // Sorting ensures stronger attack on right globally not defense
    /*
      [[5,5], [6,3], [6,10], [7,2]]

      After Sorting : 
      [[5,5], [6,10], [6,3], [7,2]]

      Defenses :
      [5, 10, 3, 2]

      5 < 10
      weak++
    */

    int weak = 0;
    int bestDefenseRight = 0;

    // Scanning from strongest attack
    for(int i = p.size() - 1; i >= 0; i--){

      int attack = p[i][0];
      int defense = p[i][1];

      if(defense < bestDefenseRight)
        weak++; 

      bestDefenseRight = max(defense, bestDefenseRight);
    }

    return weak;
    }
};