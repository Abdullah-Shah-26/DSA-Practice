#include<list>
#include<iostream>
using namespace std;
class Node{    // node class -> to point to other node
    public:
        int data;   // value at node
        Node*next;  // node pointer to point the next node 

    Node(int val){ // constructor
        data = val;
        next = NULL;
    }
};
class List {     //list class -> to combine all nodes
    public: 
    Node* head;  // stores head and tail ptr 
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

    //! function to print linked list

    void printLL(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp->data <<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<< endl;
    }

};
int main(){
    List ll;    //!to create linked list
    
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

        ll.printLL();
}