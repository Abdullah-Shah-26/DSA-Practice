#include <bits/stdc++.h>
using namespace std;

class TextEditor {
public:
  list<char> editor;
  list<char>:: iterator it;

  string remainingText(){
  string ans = "";

  auto i = it; 
  int cnt = 10; // We want atmax 10 among those remains

  while(cnt > 0 && i != editor.begin()){
      i--;
      cnt--;
      ans += *i;
  }

  reverse(begin(ans), end(ans));
  return ans;
  }

  TextEditor() {
  it = editor.begin();
  }
  
  void addText(string text) {
  for(auto ch : text){
      it = editor.insert(it, ch);
      it++;
  }
  }
  
  // 'It' is after text, so we need to move it back to point to last char & delete it
  int deleteText(int k) {
  int deleted = 0;

  while(it != editor.begin() && k > 0){
      k--;
      it--;
      deleted++;
      it = editor.erase(it);
  }

  return deleted;
  }
  
  string cursorLeft(int k) {
  while(it != editor.begin() && k > 0){
      it--;
      k--;
  }
  return remainingText();
  }
  
  string cursorRight(int k) {
  while(it != editor.end() && k > 0){
      it++;
      k--;
  }
  return remainingText();
  }
};