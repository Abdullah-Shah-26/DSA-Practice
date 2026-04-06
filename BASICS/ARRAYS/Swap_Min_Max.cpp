#include<iostream>
using namespace std;
int main(){
    int Ar[6]={3,4,1,2,6,9};
    int min=Ar[0];
    int max=Ar[0];
    int minIndex=0;
    int maxIndex=0;
    for(int i=0;i<6;i++){
        if (Ar[i]<min){
            min =Ar[i];
            minIndex=i;
        }
        if (Ar[i]> max){
            max =Ar[i];
            maxIndex=i;
        }
          cout <<Ar[i]<<" ";
    }
   cout<<endl;
    Ar[minIndex]=max;
    Ar[maxIndex]=min;
    for (int i=0; i<6 ;i++){ 
         cout <<Ar[i]<<" ";
      
}
}