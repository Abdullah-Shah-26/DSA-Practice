#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = NULL;
    }
};
class Deque{
    Node* front;
    Node* rear;

    public:

    Deque(){
        front = rear = NULL;
    }
    // push front
void push_front(int x){
    // cheking if deque is empty
    if(front == NULL)
    {
        front = rear = new Node(x); // both will point  to new node
        cout<<"pushed "<<x<< " in front of deque\n";
        return;

    }
    //deque not empty
    else{
        Node* temp = new Node(x);
        temp->next = front;
        front->prev = temp;
        front = temp;
        cout<<"pushed "<<x<< " in front of deque\n";
        return;
    }

}

    // push back
    void push_back(int x){
        // cheking if deque is empty
        if(front == NULL)
        {
            front = rear = new Node(x); // both will point  to new node
            cout<<"pushed "<<x<< " at back of deque\n";
            return;
    
        }
        //deque not empty
        else{
            Node* temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout<<"pushed "<<x<< " at back of deque\n";
            return;
        }
    }

    // pop front 

        void pop_front(){
            // deque is empty
            if(front == NULL){
                cout<<" deque underflow \n";
                return;
            }
            // not empty
            else{
                Node* temp = front;
                cout<<"popped "<<temp->data<<" from front\n";
                front = front->next;
                delete temp;
                // greater than 1 node
                if(front != NULL){
                        front->prev = NULL;

                }
                // edge case - Single node
                else{
                    rear = NULL;
                }
            }
        }

    // pop back

    void pop_back(){
        // deque is empty
        if(front == NULL){
            cout<<" deque underflow \n";
            return;
        }
        // not empty
        else{
            Node* temp = rear;
            cout<<"popped "<<temp->data<<" from back\n";
            rear = rear->prev;
            delete temp;
            // greater than 1 node
            if(rear != NULL){
                    rear->next = NULL;

            }
            // edge case - Single node
            else{
                front = NULL;
            }
        }
    }

    //start 
int start()
{
    if(front == NULL)
        return -1;
    
    else 
        return front->data;
}
    //end
    int end()
{
    if(front == NULL)
        return -1;
    
    else 
        return rear->data;
}
};

int main(){
    Deque dq;

    dq.push_back(5);
    dq.push_front(8);
  

    dq.pop_back();
    dq.pop_front();

    cout<< dq.start() <<endl;

}