class Solution {
public:

// TC = O(N!)
// SC = O(N * N!) + O(N)
//     len * no of perms + substr   + recursion
    void solve(string &temp,string &s,vector<bool>&used,unordered_set<string>&st, const int &n){

      st.insert(temp);
    

      for(int j = 0;j < n; j++){
        if(used[j]){
          continue;
        }
        
        // Take
        used[j] = 1; 
        temp += s[j];
        solve(temp,s,used,st,n);

        // Not Take
        temp.pop_back();
        used[j] = 0;
      }
    }

    int numTilePossibilities(string tiles) {
    unordered_set<string>st;
    int n = tiles.size();
    string temp = "";
    vector<bool>used(n,0);
    solve(temp,tiles,used,st,n);
    return (int)st.size() - 1;
    }
};

//* Appraoch 2 

class Solution {
public:
    int cnt = 0;
  // TC = O(N!)
  // SC = O(N)
   void solve(int freq[26]){
      cnt++;

      for(int i = 0; i < 26; i++){
        if(freq[i] == 0){
          continue;
        }

        freq[i]--;
        solve(freq);
        freq[i]++;
      }
    }


    int numTilePossibilities(string s) {
    int arr[26] = {0};
    for(char &ch : s){
      arr[ch-'A']++;
    }
    solve(arr);
    return cnt -1;
    }
};