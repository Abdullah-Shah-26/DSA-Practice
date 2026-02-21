#include<iostream>
#include<algorithm>  // to use reverse
#include<string>
using namespace std;


//reverse half of even string


int main(){
    string s = "raghav";
    int i=0;
    int n= s.length();

    reverse(s.begin(),s.begin()+n/2);
    
    // int j=n/2-1; // -1 to remove the '\0' 
    // while(i<j){
    //     char temp = s[i];
    //     s[i] = s[j] ;
    //     s[j] = temp ;
    //     i++;
    //     j--;
    // } 
    cout<<s;

}