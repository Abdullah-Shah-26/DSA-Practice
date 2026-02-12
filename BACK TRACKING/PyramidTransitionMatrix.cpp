

class Solution {
public:
// TC = Exponential O(L)^N
    unordered_map<string,bool>memo;

    bool solve(string &curr, unordered_map<string,vector<char>>&mp, int idx, string &above){
      if(curr.size() == 1){ // Reached The Top
        return true;
      }

      if(idx == curr.size() - 1){ // Curr Row End - Move To Above Row 
        if(memo.count(above)) return memo[above];
        string newTop = "";
        bool res = solve(above, mp, 0, newTop);
        memo[above] = res;
        return res;
      }

      string pair = curr.substr(idx,2);

      if(!mp.count(pair)){
        return false;
      }

    for(char &ch : mp[pair]){
      above.push_back(ch);
      if(solve(curr, mp, idx+1, above)) {
        return true;
      }
      above.pop_back();
    }
  return false;
}
    bool pyramidTransition(string bottom, vector<string>& allowed) {
    unordered_map<string,vector<char>>mp;
    int n = bottom.size();
    int m = allowed.size();

    for(auto &s : allowed){
      mp[s.substr(0,2)].push_back(s[2]);
    }
    string top = "";
    return solve(bottom, mp, 0, top);
    }
};
