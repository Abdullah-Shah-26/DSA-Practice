#include<iostream>
#include<string>
using namespace std;

class Teacher{
    //CONSTRUCTOR OVERLOADING - EX OF POLYMORHISM

    public:
        Teacher(){     //1 constructor NON PARAMETERIZED CONSTRUCTOR                                                         
            dept = "CSE"; 
        }

        Teacher(string n, string d, string s,double sal){ //2nd constructor PARAMETERIZED CONSTRUCTOR
            name = n;
            dept = d;
            sub = s;
            salary = sal;
        }
    private :
        double salary;

    public :
        string name;
        string dept;
        string sub;

        public:
        void getinfo(){
            cout<<"name : "<<name<<endl;
            cout<<"dept : "<<dept<<endl;
        }
      
};
int main(){
    Teacher t1("sara","cse","c++",200000);
    t1.getinfo();
} 
