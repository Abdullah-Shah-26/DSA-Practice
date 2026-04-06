#include<iostream>
#include<string>
using namespace std;
class person{
    public:
    string name;
    int age;
};
class student : public person{
    public:
        int rollno;
};
class gradstudent : public student{
    public:
        string researcharea;
};
int main(){
    gradstudent s1;
    s1.name = "mahima", s1.researcharea = "AI";
    cout<<"name : "<<s1.name<<"\n";
    cout<<"resercharea : "<<s1.researcharea<<"\n";
    
}