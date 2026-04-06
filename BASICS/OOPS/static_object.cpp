#include<iostream>
#include<string>
using namespace std;
class ABC{
    public:
//! TO DEMONSTRATE STATIC VARIABLES HAVE LIFETIME TILL THE END OF THE PROGRAN
    ABC(){
        cout<<"constructor call"<<endl;
    }
    ~ABC(){
        cout<<"destructor call"<<endl;
    }
};
int main(){
    if(true){
        static ABC obj;
    }
    cout<<"end of main function"<<endl;
}