#include <bits/stdc++.h>
using namespace std;

// reursive func
void printNum(int n){
  if(n == 1){  // base case 
    cout<<"1\n";
    return;
  }
  cout<< n <<endl;
  printNum(n-1);  // recursive call
}
int main(){
  printNum(4);
  return 0;
}