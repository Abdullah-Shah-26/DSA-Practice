class Solution {
public:
    int n;
    int maxScore;

    // TC = O(n * 2^n)
    // SC = O(n)
    void solve(int i,vector<int>&score, vector<string>&words, int curScore, vector<int>&freq){
    maxScore = max(curScore, maxScore);  
    if(i >= n){
      return;
    }

    int tempScore = 0;
    int j = 0;
    vector<int>tempFreq = freq;
    while(j < words[i].length()){
      char ch = words[i][j];

      tempFreq[ch-'a']--;
      tempScore += score[ch-'a'];

      if(tempFreq[ch-'a'] < 0){
        break;
      }

      j++;
    }

    if(j == words[i].length()){
      // Take
      solve(i+1,score,words,curScore + tempScore, tempFreq);
    }
    freq = tempFreq;
    // Not Take
    solve(i+1, score,words, curScore, freq);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    n = words.size();
    maxScore = -1e9;
    vector<int>freq(26);

    for(char &ch : letters){
      freq[ch-'a']++;
    }
    solve(0,score,words,0,freq)
    return maxScore;
    }
};