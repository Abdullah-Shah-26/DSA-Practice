#include <bits/stdc++.h>
using namespace std;

// reursive func
int fact(int n){
  if(n == 0){
    return 1;
  }
  return n*fact(n-1);

}
int main(){
  cout<<" factorial is : "<<fact(4);
   
  return 0;
}