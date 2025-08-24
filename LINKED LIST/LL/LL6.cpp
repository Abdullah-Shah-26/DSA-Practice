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

    void push_front(int val){ //!  O(1)
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


    void push_back(int val){ //O(1)
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
    void pop_front() {// O(1)
        if(head == NULL ){
            cout<<" LL is empty "<<endl;
            return ; 
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    //! POP BACK LOGIC
    void pop_back(){ //O(n)
        if(head == NULL ){
            cout<<" LL is empty "<<endl;
            return ; 
        }
        Node* temp = head;
        while(temp->next!= tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
        //! LOGIC OF INSERT
        void insert(int val,int pos){ //O(n)
            if(pos < 0)
            return;
            if(pos == 0)     // push front wala case
            push_front(val);
            return;
            
            Node* temp = head;

            for(int i=0;i<pos-1;i++){
                temp = temp->next;  
            }
                Node* newNode = new Node(val); 
             newNode->next = temp->next;

             temp->next = newNode;
        }

        //! LOGIC OF SEARCH IN LL
            int search(int key){ // O(n)
                Node* temp = head;
                int idx = 0;


                while(temp != NULL ){
                    if(temp->data == key){
                        return idx;
                    }
                    temp = temp->next;
                    idx++;
                }
                return -1;
            }
        
        void printLL(){ //O(1)
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

    ll.printLL(); 
    cout<<ll.search(2);//at idx 1



}