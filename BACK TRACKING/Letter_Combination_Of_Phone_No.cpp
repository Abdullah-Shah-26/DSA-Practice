// TC = O(4 ^ N * N) 
// SC = O(N)
class Solution {
public:
    void solve(int idx, vector<string>& ans, string& temp,
               unordered_map<char, string>& d, string& digits) {
        if (idx >= digits.size()) {
            ans.push_back(temp);
            return;
        }

        char ch = digits[idx];
        string s = d[ch];
        for (auto& ch : s) {
            temp += ch;
            solve(idx + 1, ans, temp, d, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        unordered_map<char, string> d = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> ans;
        string temp;
        solve(0, ans, temp, d, digits);
        return ans;
    }
};