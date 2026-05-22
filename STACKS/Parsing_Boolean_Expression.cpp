#include <bits/stdc++.h>
using namespace std;

// TC = O(N) = SC

class Solution {
public:
  char solve(vector<char> &values, char op){
    if(op == '!'){ // Will only have 1 char to evaluate, Ex : !(F), !(T)
      return values[0] == 't' ? 'f' : 't';
    }
    else if(op == '&'){

      for(auto &ch : values){
        if(ch == 'f') return 'f';
      }
      return 't';
    
    }
    else{ // (op == '|')

      bool hasT = false;
      for(auto &ch : values){
        if(ch == 't'){
          hasT = true;
          break;
        }
      }

      return hasT == true ? 't' : 'f';
    }
  }

  bool parseBoolExpr(string s) {
  int n = s.size();

  stack<char> st;

  for(int i = 0; i < n; i++){
    if(s[i] == ',')
      continue;

    if(s[i] == ')'){
      vector<char> values;

      while(st.top() != '('){
        values.push_back(st.top());
        st.pop();
      }
      st.pop(); // Popped '('
      char op= st.top(); // !, &, |
      st.pop();

      st.push(solve(values, op));
    }
    else{
      st.push(s[i]);
    } 
  }

  return st.top() == 't';
  }
};