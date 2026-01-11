#include<deque>  //similar to list 
#include<iostream>
using namespace std;
        int main(){
            deque<int>d = {1,2,3,4,5};

            for(int val:d ){
                cout<< val << " ";
            }
            cout<<endl;

            cout<<" element at specific index : "<< d[2]<< endl;
        }