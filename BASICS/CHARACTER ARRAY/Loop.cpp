#include<iostream>
using namespace std;

int main(){
    char str[12];//can only take 12 char including spaces 

    cout <<"enter char array: ";
cin.getline(str,12);

for(char ch: str){
    cout << ch <<" ";

}
cout << endl;
return 0;
}