#include<set>
#include<iostream>
using namespace std;
int main(){
    set<int>s; //ignores repeated value
     
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    s.insert(4);
    s.insert(4);
    
    for(auto val:s){
        cout<<val<<" ";

    
    }
    cout<<endl;
    cout<<"Lower Bound : "<< *(s.lower_bound(4))<<endl;//should have returned s.end() iterator if not found 
                                               //RETURNS VALUE JUST > OR EQUAL TO KEY IF FOUND
    cout<<"Upper Bound : "<< *(s.upper_bound(4))<<endl;

}