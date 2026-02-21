#include<string>
#include<iostream>
using namespace std;
class Teacher{
    private:
        double salary;
    public:
        string name;
        string dept;
        string sub;

    Teacher(string name,string dept, string sub,double n){
        this->name = name;
        this->dept = dept;
        this->sub = sub;
        this->salary = salary;

    }

    //custom copy constructor  // it needs a referance object to copy to another object  
    Teacher(Teacher &orgobj){   ///
        cout<<"i am custom copy constructor"<<endl;
        this->name= orgobj.name;
        this->dept = orgobj.dept;
        this->sub = orgobj.sub;
        this->salary = orgobj.salary;
    }
    void getinfo(){
        cout<<"name : "<<name<<endl;
        cout<<"dept : "<<dept<<endl;
        cout<<"sub : "<<sub<<endl;
       
    }
};
int main(){
    Teacher t1("mahima","CSE","C++",100000);

    //invoking default copy constructor
    Teacher t2(t1);
    t2.getinfo();
}