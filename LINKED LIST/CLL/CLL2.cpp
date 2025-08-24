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
class CircularLL{
    Node* head;
    Node* tail;


    public:
    CircularLL(){
        head = tail = NULL;
    }
    //! Print CLL
        void print(){
            if(head == NULL){
                cout<<" CLL is empty";
                return;
            }
            cout<< head->data << " -> ";
            Node* temp = head->next;

            while(temp != head){
                cout<< temp->data <<" -> ";
                temp = temp->next;
            }
            cout<< temp->data ;
        }
        //! INSERT AT TAIL

        void insertAtTail(int val){
            Node* newNode = new Node(val);
            
            if(head == NULL){ //cll is empty
                head = tail = newNode;
                tail->next = head;
            }
            else{ //CLL not empty 

                newNode->next = head;

                tail->next = newNode;
                tail = newNode;
                          

            }
        }
};
int main(){
    CircularLL ll;

    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);

    ll.print();



}