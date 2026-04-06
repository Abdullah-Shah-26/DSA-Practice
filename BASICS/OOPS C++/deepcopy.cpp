#include<string>
#include<iostream>
using namespace std;
class student{
    public:
    string name;
    double *cgpaPtr;  // ptr pointing to nothing

    student(string name,double cgpa){ //deafult copy constructor
        this->name = name;
        cgpaPtr = new double;   // now ptr is pointing to a memory location which can store double
        *cgpaPtr = cgpa;        //stroring value of cgpa in location of ptr by derefrencing

    }
    //!custom copy constructor for deep copy

    student(student &orgobj)   {
        this->name = orgobj.name;
        cgpaPtr = new double;
        *cgpaPtr = *orgobj.cgpaPtr;
        
        
    }


    void display(){
        cout<< " name : "<< name<<endl;
        cout<< " cgpa : "<<*cgpaPtr<<endl;
    }
};
int main(){
    student s1("rahul kumar",8.9);
    student s2(s1);
    s1.display();            //! DEEP COPY NO PROBLEM boy 
    *(s2.cgpaPtr) = 9.2;    //? only s2 will get changed  
    s2.name = "Neha kumari";
    s1.display();
    s2.display();

}