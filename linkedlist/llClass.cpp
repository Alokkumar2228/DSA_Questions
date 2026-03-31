#include<iostream>
using namespace std;

class Node{
    public:
    int val ;
    Node *next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
    public:
    Node *head;
    Node *tail;
    int size;

    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    //temp->next->val =  (*(*temp).next).val

    void insertAtEnd(int val){
        Node *temp = new Node(val);
        if(size == 0){
            head = tail = temp;
            size ++;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtBegin(int val){
        Node *temp = new Node(val);
        if(size == 0){
            head = tail = temp;
            size ++;
        }else{
            temp->next = head;
            head = temp;   
        }
    }

    void insertAtPosition(int val , int idx){
         Node *temp = new Node(val);
         Node *current = head;
         int count = 0 ;
         while(current != NULL && count < idx ){
            if(count == (idx-1)){
                temp->next = current->next;
                current->next = temp;
                break;
            }else{
                current = current->next;
                count++;
            }
         }
    }

    void deleteAtPosition(int idx){
        for(int i=1 ; i<=idx-1)po

    }

    void getAtIndex(int idx){
        if(idx == 0) cout<< head->val<<endl;
        else if(idx == size) cout<<tail->val<<endl;
        else{
            Node *temp = head;
            for(int i=1 ; i<= idx ; i++){
                temp = temp->next;
            }

            cout<<temp->val<<endl;
            
        }

    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }

        cout<<endl;
        
    }

};



int main(){

    LinkedList ll;
    // ll.insertAtEnd(10);
    // ll.insertAtEnd(20);
    // ll.insertAtEnd(30);
    // ll.insertAtEnd(40);
    // ll.insertAtEnd(50);

    ll.insertAtBegin(100);
    ll.display();
    ll.insertAtBegin(200);
    ll.display();
    ll.insertAtBegin(300);
    ll.display();
    ll.insertAtBegin(400);
    ll.display();
    ll.insertAtBegin(500);
    ll.display();
    ll.insertAtBegin(600);
    ll.display();

    ll.insertAtPosition(800,2);

    ll.display();

    ll.insertAtPosition(900,4);

    ll.display();

    ll.getAtIndex(3);






    




    return 0;
}