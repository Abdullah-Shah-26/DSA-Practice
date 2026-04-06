#include<iostream>
#include<string>
using namespace std;
class student{
    public:
    int rollno;
    string name;
};
class teacher{
    public: 
        string subj;
        double salary;
};
class TA : public student , public teacher{

};
int main(){
    TA t1;
    t1.name = "umaima";
    t1.subj= "c++";
    cout<<t1.name<<" "<<t1.subj;
}