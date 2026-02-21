class Solution {
public:
    // TC = O(N!)
    // SC = O(N)

    bool solve(int i,vector<int>&res,vector<bool>&used, const int &n){
    if(i >= res.size()){
      return true;
    }

    if(res[i] != -1){
      return solve(i+1,res,used,n);
    }

    for(int num = n; num >= 1; num--){

      if(used[num]){
        continue;
      }

      res[i] = num;
      used[num] = 1;

      if(num == 1){
        if(solve(i+1,res,used,n)){
          return true;
        }
      }
      else{
        int j = i + num;
        if(j < res.size() && res[j] == -1){
          res[j] = num;
          if(solve(i+1,res,used,n)){
            return true;
          }
          res[j] = -1;
        }
      }
      res[i] = -1;
      used[num] = 0;
    }
    return false;
 }

    vector<int> constructDistancedSequence(int n) {

    vector<int>res(2*n-1,-1);
    vector<bool>used(n+1,0);

    solve(0,res,used,n);

    return res;
    }
};