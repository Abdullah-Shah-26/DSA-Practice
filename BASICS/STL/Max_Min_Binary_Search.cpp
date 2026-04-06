#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v = {1,2,3,4,5,6};
    cout<<"max : "<<*(max_element(v.begin(),v.end()))<<endl;
    cout<<"min : "<<*(min_element(v.begin(),v.end()))<<endl;
    int tar=5;
    cout<<"is target found :"<<binary_search(v.begin(),v.end(),tar)<<endl;
    

}