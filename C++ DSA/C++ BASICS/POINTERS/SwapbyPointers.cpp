#include<iostream>//! swap 2 nos by pass by referance USING POINTERS
using namespace std;
void swap(int* a,int* b){
    int temp= *a;
    *a=*b;
    *b =temp;
}
int main(){
int x=12;
int y=20;
cout << x <<" "<<y<<endl;
swap(&x,&y);
cout << x <<" "<<y<<endl;
}