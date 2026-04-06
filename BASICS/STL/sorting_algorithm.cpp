#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int arr[] = {1,4,2,6,5,9};
       cout <<endl;
        sort(arr,arr+6);    //can sort both vec and arr.
        for(int val:arr){
        cout<<val<<" ";

        }
    cout <<endl;
    vector<int>v= {30,38,58,02,47,84};
    cout <<endl; 
    for(int val:v){
        cout<<val<<" ";
    }
    cout <<endl; 
    sort(v.begin(),v.end());

    for(int val:v){
        cout<<val<<" ";
    }
    //to sort in reverse order

    sort(v.begin(),v.begin()+6,greater<int>());
    cout <<endl; 
    for(int val:v){
        cout<<val<<" ";
    }
 
}
