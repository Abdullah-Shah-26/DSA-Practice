#include<iostream>
#include<string>
using namespace std;

class parent{
    public: 
    void getinfo(){
        cout<<"parent class";
    }
};
class child : public parent{
    public: 
    void getinfo(){
        cout<<"child class";
    }
};
int main(){
    child c1;
c1.getinfo();
}