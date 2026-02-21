class Solution {
public:
    void solve(int idx, vector<int>&temp, vector<int>&arr, vector<vector<int>>&res)
    {
      if(temp.size() >= 2)
      {
        res.push_back(temp);
      }
      unordered_set<int>st;
  
      for(int i = idx; i < arr.size(); i++)
      {
        if((temp.empty() || temp.back() <= arr[i])
        && (st.find(arr[i]) == st.end())) {
        temp.push_back(arr[i]);
        solve(i+1,temp,arr,res);
        temp.pop_back();
        st.insert(arr[i]);
        }
      }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>>res;
    vector<int>temp;
    solve(0,temp,nums,res);
    return res;    
    }
};