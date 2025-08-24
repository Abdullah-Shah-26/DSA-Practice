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
};
int main(){
    DoublyList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);

    dll.print();


}
