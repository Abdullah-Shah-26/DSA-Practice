#include <bits/stdc++.h>
using namespace std;
vector<string>solve(string &s,unordered_set<string>&st){

    if(s.empty()){
        return {""};
    }
    vector<string>res;  
    for(int l = 1; l <= s.size(); l++){
        string curWord = s.substr(0,l);
        if(st.count(curWord)){
            string remWord = s.substr(l);
            vector<string> remResult = solve(remWord,st);
            for(string &w : remResult){
                string toAdd = curWord + (w.empty() ? "" : " ") + w;
                res.push_back(toAdd);
            }
        }
    }
    return res;

}

vector<string> wordBreak(string &s, vector<string> &dict)
{
    int n = s.size();

    unordered_set<string>st;
    for(auto &word : dict){
        st.insert(word);
    }
    return solve(s,st);
}


