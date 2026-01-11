#include<string>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
string s = "bac";
// if(next_permutation(s.begin(),s.end())){
//     cout<<s;
// }
// else cout<<"no next permutaution";


if(prev_permutation(s.begin(),s.end())){
    cout<<s;
}
else cout<<"no prev permutaution";
}