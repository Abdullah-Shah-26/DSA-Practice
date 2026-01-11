#include<iostream>
#include<vector>
using namespace std;
int main()
{
  
    vector<int>vec; // creates a vec of size = 0

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    cout<<"size of vector is : " <<vec.size()<<endl;
    cout<<"capacity of vector is : "<<vec.capacity()<<endl;

    vec.pop_back();
    
    vec.emplace_back(6);

    cout<<"front : "<<vec.front()<<endl;
    cout<<"back : "<<vec.back()<<endl;

    cout<<"value present at a particular index : "<<vec.at(0)<<endl;
    cout<<"another way to access values : "<<vec[1]<<endl; 

    cout<<"for each loop is used to print all the vector values: "<<endl;

    for(int val:vec){
        cout<<val<<" ";
    }           
} 