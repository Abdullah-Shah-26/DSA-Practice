#include<vector>
#include<iostream>
#include<stdbool.h>
#include<algorithm>
using namespace std;
bool comparatar(pair<int,int>p1, pair<int,int>p2){
    if(p1.second<p2.second)return true; //sorting based on 2nd elements
    if(p1.second>p2.second)return false;
    if(p1.first<p2.first)return true ; //sorting based on 1st elements
    else return false;
}
int main(){


    vector<pair<int,int>>v = { {2,1}, {3,1}, {5,2}, {7,2}};

    sort(v.begin(),v.end(),comparatar);

    for(auto p:v){
        cout<<p.first<< " "<<p.second<<endl;
    }
    cout<<endl;


}