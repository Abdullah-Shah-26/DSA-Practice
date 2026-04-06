#include<iostream>
#include<climits>
#include<string>
#include <algorithm>     ///! SHOULD BE USED FOR reverse(s.begin(),s.end())
using namespace std;
        int main(){
            string s="ABDULLAH";
            cout<<s<<endl;
            
            s.push_back('s'); //! TO ADD CHARACTERS FROM LAST
    
            cout<<s<<endl;

            s.pop_back();  //! TO REMOVE CHARACTERS FROM LAST    
                            // no argument needed

            cout<<s<<endl;

            s.append(" SHAH");  //! TO ADD NEW STRING FROM LAST   

            cout<<s<<endl;

            cout<<s.length()<<endl;
            s.clear();  //! TO DELETE A STRING 
            cout<<s.length()<<endl;

            //! "+ OPERATOR"

            string s1 = "raghav";
            cout<<s1<<" "<<s1.length()<<endl;

            s1+="garg";

            cout<<s1<<" "<<s1.length()<<endl;

            //! reverse a string

            reverse(s1.begin(),s1.end());

            cout<<s1<<endl;





        
        }