// TC = O(2^N)
// SC = O(N)
class Solution {
  public:
    vector<string>res;
    int n;
    void solve(int open, int close,string &cur){
        
        if(cur.size() == 2*n){
            res.push_back(cur);
            return;
        }
        if(open < n){
            cur += '(';
            solve(open +1, close, cur);
            cur.pop_back();
        }
        if(close < open){
            cur += ')';
            solve(open, close + 1, cur);
            cur.pop_back();
        }
    }
    
    vector<string> generateParentheses(int N) {
    string cur = "";
    n = N/2;
    solve(0,0,cur);
    return res;
    }
};