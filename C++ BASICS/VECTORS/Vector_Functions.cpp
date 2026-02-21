#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>vec;
    cout <<" before push back size="<<vec.size()<<endl;
    vec.push_back(25); // adds 1 index with 25 value in it 
     vec.push_back(35);
      vec.push_back(45);
       vec.push_back(55);
       cout <<" after push back size="<<vec.size()<<endl;
       cout << vec.capacity()<<endl; //!JABHI VECTORE KI SIZE CHOTI PADEGI USKI CAPACITY DOUBLE HOJAYEGI
        vec.push_back(5);
       cout << vec.capacity()<<endl;
       vec.pop_back();//last value gets deleted 55
       cout<<vec.front()<<endl; //display front value 
 cout<<vec.back()<<endl;//display last  value 

 cout<<vec.at(0)<<endl; // looking value at particular index
 return 0;
       }