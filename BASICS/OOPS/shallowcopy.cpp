#include<string>
#include<iostream>
using namespace std;
class student{
    public:
    string name;
    double *cgpaPtr;  // ptr pointing to nothing

    student(string name,double cgpa){ //deafult copy constructor
        this->name = name;
        cgpaPtr = new double;  // now ptr is pointing to a memory location which can store double
        *cgpaPtr = cgpa;  //stroring value of cgpa in location of ptr by derefrencing

    }
    //custom copy constructo 
    student(student &orgobj) //simply copy orginal data values to new obj values
    {
        this->name = orgobj.name;
        this->cgpaPtr = orgobj.cgpaPtr;
    }


    void display(){
        cout<< " name : "<< name<<endl;
        cout<< " cgpa : "<<*cgpaPtr<<endl;
    }
};
int main(){
    student s1("rahul kumar",8.9);
    student s2(s1);
    s1.display();            //! SHALLOW COPY PROBLEM
    *(s2.cgpaPtr) = 9.2;    //? s1 is getting changed but we want change only in s2
    s1.display();

}