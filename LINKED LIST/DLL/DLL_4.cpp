#include<list>
#include<iostream>
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
class DoublyList{
    public:
    Node* head;
    Node* tail;
    
    DoublyList(){
        head = tail = NULL;
    }
    //! to print 

    void print(){
        Node* temp = head;
        while(temp != NULL ){
        cout<< temp->data << "<->";
        temp = temp->next;

    }
    cout <<"NULL"<<endl;
    }
    //! PUSH BACK
    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){ // dll is empty
            head = tail = newNode;
            return;

        }else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;

        }
    }   
    //! POP FRONT

        void pop_front(){
            if(head == NULL)//  DLL is empty
            {
                cout<<"DLL is empty";
                return;
            }
            Node* temp = head;
            head = head->next;
            if(head!= NULL)  
            head->prev = NULL;  

            temp->next = NULL;
            delete temp;
        }

        //! POP BACK
           void pop_back(){

            if(head == NULL)//  DLL is empty
            {
                cout<<"DLL is empty";
                return;
            }  
            
            Node* temp = tail;
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL;
            }
            temp->prev = NULL;
            delete temp;
           }
        };
int main(){
    DoublyList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);

    dll.print();

    dll.pop_back();
    dll.pop_back();

    dll.print();
}