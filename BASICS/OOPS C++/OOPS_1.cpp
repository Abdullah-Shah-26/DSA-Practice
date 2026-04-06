#include<iostream>
#include<string>
using namespace std;
//! CREATING CLASSES OBJECTS AND PRIVATE MEMBERS & PUBLIC MEMBERS
    
class Teacher{
    private:
            double salary;
    
    public:
            //properties or attributes
            string name;
            string dept;
            string sub;

    //setter -> function to set private members
        void setsalary(double s){

            salary = s; //sets the salary to s 
        }
    
    //getter -> function to get private members
        double getsalary(){
            return salary;
        }

};
int main(){
    Teacher t1; //creating an object t1

    t1.name = "shraddha";
    t1.dept = "CSE";
    t1.sub =  "C++";

    t1.setsalary(250000); //since its a private member it can t be accessed directly

    cout<<"Name: " <<t1.name<<endl;
    cout<<"Dept: " <<t1.dept<<endl;
    cout<<"sub:  "<<t1.sub<<endl;

    cout<<"salary: "<<t1.getsalary();
    




}

