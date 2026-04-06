#include<vector>
#include<iostream>
using namespace std;
int main(){
    pair<int,int>p = {1,2};
    pair<char,int>p1 = {'a', 100};
    pair<string, int>p2 = { "ABDULLAH", 18};

    cout<<"ACCESSING ELEMENTS OF A PAIR  : "<<endl;

    cout<<p.first<< " "<< p.second<< " "<<endl;

    pair<int,pair<int,int>> p3 = {1,{15,20}};
    
    pair<pair<string,int>,pair<char,int>>p4 = { {"SHAH",1000}, { 'A', 999}};

    cout<<"ACCESSING PAIR INSIDE A PAIR : "<<endl;

    cout<<p3.first<<"  "<<endl;
    cout<<p3.second.first<<endl;
    cout<<p3.second.second<<endl;


    cout<<p4.first.first<<"  "<<p4.first.second<<endl;
    cout<<p4.second.first<<"  "<<p4.second.second<<endl;



}