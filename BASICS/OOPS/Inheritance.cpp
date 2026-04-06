#include<iostream>
#include<string>
using namespace std; //*SINGLE LEVEL INHERITANCE
//!PARENT CLASS
class person{
    public:
        string name;
        int age;

    person(string name,int age){
        this->name = name;
        this->age = age;
    }

};
//!CHILD CLASS
class student : public person {
    public:
        int rollno;
    //explicitly calling parent class constructor from child class and passing values
    student(string name, int age, int rollno ):person(name ,age){
        this->rollno = rollno;
    }
    void getinfo(){
        cout<<"name : "<<name<<endl;
        cout<<"age  : "<<age <<endl;
        cout<<"rollno : "<<rollno<<endl;
    }


};
int main(){
    student s1("mahima",18,25);
    s1.getinfo();
}