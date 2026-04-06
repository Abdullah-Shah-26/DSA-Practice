#include<iostream>
using namespace std;
int main(){



 int x,y;
 cout<<" enter values for x and y ";
 cin>>x; cin>>y;
 if(x>0 && y>0)
    cout<< "1st q";

else if(x<0 && y>0)
    cout << " 2nd q";

    else if(x<0 && y<0)
    cout << " 3rd q";

    else 
    cout<< " 4th q";
}
