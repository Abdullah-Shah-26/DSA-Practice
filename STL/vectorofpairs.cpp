#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<pair<int,int>>vec = { {1,2}, {3,4}, {5,6}};
    for(pair<int,int> p : vec){  //or for(auto p : vec){ cout<<p.first<<" "<<p.second<<endl; }
        cout<<p.first<<" "<<p.second<<endl;

    }
    //to insert pairs from end
    vec.push_back({ 10,20});

    vec.emplace_back(30,50);

    cout<<endl;
    
    for(auto p: vec ){
        cout<<p.first<< " "<< p.second<<endl;
    }



}