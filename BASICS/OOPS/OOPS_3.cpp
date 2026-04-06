#include<iostream>
#include<string>
using namespace std;

class Teacher{
    //CONSTRUCTOR

    public:
        Teacher(){
            dept = "CSE"; //initializing objects from constructor
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
    // t1.dept = "ece";
    t1.sub = "maths";

    cout<<t1.dept;
}