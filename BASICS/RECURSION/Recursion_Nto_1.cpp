#include<iostream> //!RECURSION
using namespace std;
void print(int n){//FUNCTION
    if(n==0) return;//BASE CASE JAISE FOR LOOP KE ANDAR CONDITION
    cout<<n<<endl; 
    print(n-1);// FUNCTION KE ANDAR FUNCTION KU CALL LAGANA = RECURSION
}
int main(){
    int n;
    cout<<"enetr n:";
    cin>>n;
    print(n);// MAIN KE ANDAR FUNCTION KU CALL LAGANA 
}