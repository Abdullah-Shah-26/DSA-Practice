#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<int>vec={1,2,3,4,5};

    for(int val:vec){
        cout<<val<<" ";
    }
    cout<<endl;
    
    // vec.erase(vec.begin());
    // cout<<"erased the first element"<<endl;

    vec.erase(vec.begin()+1 , vec.begin()+3);
    cout<<"erased 2 and 3"<<endl;

    vec.insert(vec.begin()+1 ,2);
    
    for(int val:vec){
        cout<<val<<" ";
    }
    cout<<endl;
    
    vec.clear();

    cout<<"size after clearing : "<<vec.size()<<endl;

    cout<<"capacity after clearing:  "<<vec.capacity()<<endl;

    cout<<"is the vector empty: " <<vec.empty();


    
}