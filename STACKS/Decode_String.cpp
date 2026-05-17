#include<bits/stdc++.h>
using namespace std;

// N = Len of Input String
// M = Len of Output String

// TC = O(N + M)
// SC = O(M)

class Solution {
  public:
    string decodeString(string s) {
    int n = s.size();

    stack<char> st;

    for(int i = 0; i < n; i++){
      if(s[i] != ']'){
        st.push(s[i]);
      }
      else{
        string temp = "";

        while(st.top() != '['){
          temp += st.top();
          st.pop();
        }
        st.pop(); // Popping '[' 

        // Now pop digit that was inFront of '[' 
        string d = "";
        while(!st.empty() && isdigit(st.top())){
          d += st.top();
          st.pop();
        }

        reverse(temp.begin(), temp.end());
        reverse(d.begin(), d.end());

        int k = stoi(d);
        for(int j = 0; j < k; j++){
          for(char &ch : temp){
            st.push(ch);
          }
        }
      }
    }

    string ans = "";

    while(!st.empty()){
      ans += st.top();
      st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;    
    }
};