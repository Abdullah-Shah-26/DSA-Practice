#include<iostream>
using namespace  std;
void changeA(int &b){// pass by ref using alias
    b=20;
}
int main(){
int a =10;
changeA(a);


cout <<"inside main fxn:"<<a<<endl;
return 0;
}