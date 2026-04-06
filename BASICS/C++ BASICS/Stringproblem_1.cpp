#include<iostream>
#include<climits>
#include<string>
using namespace std;

//update all even positions to a
        int main(){
            string s = "hello how are you";
            for(int i =0; i<s.length(); i++){
                if(i%2==0){
                    s[i]='a';
                }
            }
            cout<<s<<endl;









        }
