//sum of all no from 1 to n divisible by 3
#include<iostream> 
using namespace std;

int main(){
  int n,i=1,sum=0;
  cout << " enter n:\n";
  cin >>n;
  for(i=1;i<=n;i++){
    if(i%3==0){
        sum+=i;
    }
  }cout << "sum=" <<sum << endl;
return 0;
}