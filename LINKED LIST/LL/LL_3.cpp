#include<list>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};
class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);   //*syntax to create node dynamically (new keyword is used)
        if(head == NULL){ //! when we dont have any node head will point to null
            head = tail = newNode;       //we create a node now both head and tail will point to it 
            return;
        }
        else{ //means we have atleast one node and head is pointing to it
            //?newNode->next = head;
            (*newNode).next = head; //! newnode ka jo next node ptr hay it will point to head then we will change head
            head = newNode;
        }
    }


    void push_back(int val){
        Node* newNode = new Node(val); // allocates memory space in heap of type Node and space value like// new int[5]
        if(head == NULL){
            head = tail = newNode;
            return ;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    //! POP FRONT LOGIC
    void pop_front() {
        if(head == NULL ){
            cout<<" LL is empty "<<endl;
            return ; 
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    
    
    }
        void printLL(){
            Node* temp = head;
            while(temp != NULL){
                cout<< temp->data <<" -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
    

};
int main(){
    List ll;
   
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);

    ll.pop_front();

    ll.printLL();
    


}
