#include<iostream>
#include<string>
using namespace std;
//! CREATING CONSTRUCTORS EXPLICITLY 
class Teacher{
    //CONSTRUCTOR

    public:
        Teacher(){
            cout<<"HI I am Constructor";
        }
    private :
        double salary;

    public :
        string name;
        string dept;
        string sub;

      
};
int main(){
    Teacher t1 ; // constructor is automatically called as sooon as the obj is created
    t1.name = "pandu";
    t1.dept = "ece";
    t1.sub = "maths";
}
