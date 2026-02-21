#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<int>vec = {1,2,3,4,5};
    
    cout<<"1st element: "<<*(vec.begin())<<endl;
    cout<<"element present after last element (at garbage value): "<<*(vec.end())<<endl;

}