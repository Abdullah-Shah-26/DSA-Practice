class Solution {
public:
    bool isPali(string &s, int l,int r)
    {
      while(l < r)
      {
        if(s[l] != s[r])
        {
          return false;
        }
        l++;
        r--;
      }
      return true;
    }

    void solve(int idx,string &s,vector<string>&cur,vector<vector<string>>&res)
    {
      if(idx == s.size()) 
      {
        res.push_back(cur);
        return;
      }
      for(int i = idx; i < s.size(); i++)
      {
        if(isPali(s,idx,i))
        {
          cur.push_back(s.substr(idx,i-idx+1));
          solve(i+1,s,cur,res);
          cur.pop_back();
        }
      }
    }

    vector<vector<string>> partition(string s) {
    vector<vector<string>>res;
    vector<string>cur;
    solve(0,s,cur,res);
    return res;       
    }
};