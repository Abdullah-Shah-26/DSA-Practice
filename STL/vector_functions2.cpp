#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<int>vec1 = {1,2,3,4,5};

    vector<int>vec2(vec1); 

    for(int val:vec2){
        cout<<val<<" ";
        
    }
    cout<<endl;
    
    vector<int>vec3(5,-1);

    for(int val:vec3){
        cout<<val<<" ";
    }


}