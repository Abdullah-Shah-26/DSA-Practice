#include<iostream> // method 2 = making pop ops costly
#include<queue>
using namespace std;
class stack{
    int size;
    queue<int> q1;
    queue<int> q2;

    public:

    stack(){
        size = 0;
    }
    void push(int val){ // first push all elements to q1 
        q1.push(val);
        size++;
    }

    void pop(){
        if(q1.empty()){
            return;                                  
        }
        while(q1.size()  != 1){ // now to pop we'll remove all elements except the one to be popped and push them to q2
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop(); // popped the element
        size--;


        // swapping q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int top(){ //! same like pop but we will again push it in queue
        if(q1.empty()){
            return -1;                                  
        }
        while(q1.size()  != 1){ // now to pop we'll remove all elements except the one to be popped and push them to q2
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front(); // we are storing in var we need to push it again in queue since its not pop
        q2.push(ans);
        

        // swapping q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

return ans;    }


};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<st.top()<<endl;
}