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
class CircularList{
    Node* head;
    Node* tail;

    public:
        CircularList(){
            head = tail = NULL;
        }
    
    //! INSERT AT HEAD

        void insertAtHead(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = tail = newNode;
                tail->next = head;
            }
            else{
                newNode->next = head;
                head = newNode;
                tail->next = head;
            }
        }
        
        //! FUNC TO PRINT CLL

        void print(){
            if(head == NULL){
                cout<<"CLL is empty";
                return;
            }
            cout<<head->data<<" -> ";
            Node* temp = head->next;
            
            while(temp != head){
                    cout<<temp->data<<" -> ";
                    temp = temp->next;
            }
            cout<<head->data<<endl;
        }
};
int main(){
    CircularList ll;

    ll.insertAtHead(1);
    ll.insertAtHead(2);
    ll.insertAtHead(3);

    ll.print();
    
}