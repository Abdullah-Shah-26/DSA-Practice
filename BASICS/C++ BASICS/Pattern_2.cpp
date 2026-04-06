//4
//4 3 
//4 3 2
//4 3 2 1

#include<iostream>
using namespace std;
int main(){
int n=4;
for(int i = 4; i>=1; i--){
    for(int j=4; j>=i;j--){
    cout<< j <<" " ;
}
cout<<endl; 
}

cout<< " \n\n";
// A B C D 
// A B C 
// A B
// A



for(int i=1; i<=n ;i++){
    for(int j=1 ; j<=n-i+1; j++ ){
        cout<<(char)(j+64)<< " ";

    }
    cout<<endl;

}

cout<< " \n\n";
//1 2 3 4 
//1 2 3 
//1 2
//1

for (int i=1;i<=n;i++)
{
    for(int j=1 ;j<=n-i+1;j++){
        cout<< j<<" ";
    }
    cout<<endl;
}

//1 1 1 1
//2 2 2 
//3 3 
//4

cout<< " \n\n";

for(int i=1;i<=n;i++){
    for(int j=1;j<=n-i+1;j++){
        cout<<i<<" ";
    }
    cout<<endl;
}
cout<< " \n\n";

//1
//1 3
//1 3 5
//1 3 5 7

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=i;j++)            //since the last term of odd no acc to maths is 2*(n-1)
    {
        cout<< 2*j-1<<" ";

    }
    cout<<endl;
}
cout<< " \n\n";

//another alternative to print odd triangle
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=2*i-1;j++)            //since the last term of odd no acc to maths is 2*(n-1)
    {
        cout<<j<<" ";

    }
    cout<<endl;
}
cout<< " \n\n";











}