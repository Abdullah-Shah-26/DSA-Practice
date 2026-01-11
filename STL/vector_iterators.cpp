#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<int>vec = {1,2,3,4,5};

    vector<int>::iterator it;  // instead of writing this 
    for(it=vec.begin(); it!= vec.end(); it++){
        cout<< *it << " " ;
    }
    cout<<endl;

    vector<int>::reverse_iterator itr; // and this 
    for(itr = vec.rbegin(); itr != vec.rend(); itr++){
        cout<< *itr << " ";
    }
    //! just use auto it

    //for(auto it=vec.begin(); it!= vec.end; it++){
    // cout<< *it << " ":;
    // }   
}


