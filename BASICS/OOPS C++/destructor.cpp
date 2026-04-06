#include<string>
#include<iostream>
using namespace std;
class student{
    public: 
    string name;
    double* cgpaPtr;

    student(string name, double cgpa){
        this->name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    //! DESTRUCTOR
    ~student(){
        cout<<" \n hello boy I am destructor "<<endl;
        delete cgpaPtr; //to free dynamically allocated memory 
    }
    void display(){
        cout<<"name : "<<name<<endl;
        cout<<"cgpa : "<<*cgpaPtr;

    }
};
int main(){
    student s1("pandu man", 9.3);
    s1.display();

}
