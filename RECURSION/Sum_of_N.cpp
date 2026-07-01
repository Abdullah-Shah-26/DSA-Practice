#include <bits/stdc++.h>
using namespace std;

// reursive func
int sum(int n){
  if(n == 1){
    return 1;
  }
  return n + sum(n-1);

}
int main(){
  cout<<" Sum is : "<< sum(4);
   
  return 0;
}