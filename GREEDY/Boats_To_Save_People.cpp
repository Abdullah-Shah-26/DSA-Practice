#include <bits/stdc++.h>
using namespace std;

// Greedy - 2 - Pointer

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

    sort(begin(people),end(people));
    int n = people.size();
    int boats = 0;
    int i = 0, j = n-1;
    // [1,4,6,9] limit = 10
    while(i <= j){
      if(people[i] + people[j] <= limit){
        i++;
        j--;
      } else {
        // Send the heavier guy
        j--;
      }
      boats++;
    } 
    return boats;  
    }
};