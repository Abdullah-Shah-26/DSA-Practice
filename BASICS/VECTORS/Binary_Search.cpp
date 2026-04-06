#include<iostream>
#include<vector>
using namespace std;
 int binarySearch(vector<int> &input , int target){
// DEFINE SEARCH SPACE
 int lo=0;//start of search space
 int hi=input.size()-1;//end of search space
 while(lo<=hi){
    //calcl midpt for search spaxce
    int mid =lo+(hi-lo)/2;// optimised formula to prevent integer overflow+                   
    if(input [mid==target]) return mid;
    else if (input [mid <target]) {
        //discard the left mid and search target in right half
        lo =mid+1;

    }else{
        // discard the right mid and search target in left half
        hi =mid-1;
    }
 }
 return -1;
 
 
 }
int main(){
 int n;
 cout<<"enter no of elements in array="<<endl;
 cin >>n;
 vector<int> input;
 for (int i=0 ;i<n;i++){
    int x;
    cin>>x;
    input.push_back(x);
 }
 int target;
 cout<<" enter value of target=\n";
 cin>>target;
 cout<<binarySearch(input,target)<<"  is the index of target =\n";
 return 0;
}