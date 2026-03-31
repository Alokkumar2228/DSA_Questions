#include <bits/stdc++.h>
using namespace std;


class Node{
    public: 
    int val;
    Node* next;

    Node(int val){
        this->val = val ; 
        this->next = nullptr;
    }

};

class Linkedlist{
    public:

    Node* head;
    Node* tail;

    Linkedlist(){
        head = tail = nullptr;
    }

    Node* insertAttail(int val){

        Node* newNode = new Node(val);
        if(head == nullptr && tail == nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }

    };

    Node* findMid(){

        // Node* temp = head;
        Node* slow = head;
        Node* fast = head;
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<<slow->val<<endl;

        return slow;

    };


    
};

int main(){

    Linkedlist l;
    l.insertAttail(10);
    l.insertAttail(20);
    l.insertAttail(30);
    l.insertAttail(40);
    l.insertAttail(50);

    // cout<<node5->val<<endl;

    Node* midNode = l.findMid();

    cout<<midNode->val<<endl;
    
    
    return 0;
}

