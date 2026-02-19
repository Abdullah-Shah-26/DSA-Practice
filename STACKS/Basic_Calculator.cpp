__cpp_hex_float

class Solution {
public:
    int calculate(string s) {
    unsigned num = 0;
    int sign = 1;
    unsigned res = 0;
    stack<int>st;
    int n = s.size();
    for(int i = 0;i < n; i++){
      if(s[i] == ' '){
        continue;
      }
      else if(isdigit(s[i])){
        num = (num * 10) + (s[i] - '0');
      }
      else if(s[i] == '+'){
        res += (num * sign);
        num = 0;
        sign = 1;
      }
      else if(s[i] == '-'){
        res += (num * sign);
        num = 0;
        sign = -1;
      }
      else if(s[i] == '('){
        st.push(res);
        st.push(sign);
        res = 0;
        num = 0;
        sign = 1;
      }
      else if(s[i] == ')'){
        res += (num * sign);
        num = 0;
        int stack_sign = st.top(); st.pop();
        int stack_res = st.top(); st.pop();
        res *= stack_sign;
        res += stack_res;
      }
    }

    res += (num*sign); // Edge Case : When we dont get any operator at last we forget to add num in res
    return res;
    }
};