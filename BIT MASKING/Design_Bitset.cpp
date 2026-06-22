#include <bits/stdc++.h>
using namespace std;

class Bitset {

private:
  vector<int> bit;
  int cnt; // Count of 1's
  bool flag;

public:
  Bitset(int size) {
    bit.assign(size, 0);
    cnt = 0; 
    flag = false;
  }
  
  void fix(int idx) { // Convert 0 to 1, else dont touch
    if(!flag){
      if(bit[idx] == 0){
        bit[idx] = 1; 
        cnt++;
      }
    }      
    else{
      // It was flipped, i.e it was 0 before flipped to 1
      // So here 1 represents 0, convert it.
      if(bit[idx] == 1){
        bit[idx] = 0;
        cnt++;
      }
    }
  }
  
  void unfix(int idx) { // Convert 1 to 0, else dont touch
    if(!flag){ 
      if(bit[idx] == 1){
        bit[idx] = 0;
        cnt--;
      }
    }
    else{ 
      // It was flipped, i.e it was 1 before flipped to 0
      // So here 0 represents it is 1
      if(bit[idx] == 0){
        bit[idx] = 1;
        cnt--;
      }
    }  
  }
  
  void flip() {
    flag = !flag;
    cnt = bit.size() - cnt;
  }
  
  bool all() {
    return cnt == bit.size(); 
  }
  
  bool one() {
    return cnt >= 1;
  }
  
  int count() {
    return cnt;
  }
  
  string toString() {
    string ans = "";

    if(!flag){ // Not flipped, 0 is 0 & 1 is 1
      for(auto it : bit){
        if(it == 0) ans += '0';
        else ans += '1';
      }
    }    
    else{ // flipped, (0 is 1) & (1 is 0)
      for(auto it : bit){
        if(it == 0) ans += '1';
        else ans += '0';
      }
    }

    return ans;
  }
};
