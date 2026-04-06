#include<iostream>
using namespace std;
int main(){
int cp;
int sp;
cout<<" enter cost and selling price"<<endl;
cin>>cp;
cin>>sp;
if(cp>sp){
    cout<<cp-sp<< " is the loss incurred "<< endl;
}
if(cp<sp){
    cout<< sp-cp <<"is the profit "<< endl;
}
if(cp==sp){
    cout<< " neither profit nor loss";
}



}