#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    vector<int>v = { 2,3,4,5,6,7};

    // reverse(v.begin(),v.end()); /// full reverse order
    reverse(v.begin()+1,v.begin()+4); //range specific reversing
    for(int val:v){
        cout<<val<<" ";
    }
}