#include<iostream>
#include<string>
using namespace std;

class Teacher{
    //this pointer

    public:
        Teacher(){                                                         
            dept = "CSE"; 
        }

        Teacher(string name , string dept, string sub,double salary){ 
            this-> name = name; //left name is object property right name is constructor parameter
            this-> dept = dept;
            (*this).sub = sub;
            this->salary = salary;
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
            cout<<"sub : "<<sub<<endl;
        }
      
};
int main(){
    Teacher t1("sara","cse","c++",200000);
    t1.getinfo();
} 
