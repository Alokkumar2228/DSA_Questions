
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {
    public:
    Node* head;
    Node* tail;

    LinkedList(){
        head = tail = NULL;
    };

    void insertAtTail(int val){
        Node* temp = new Node(val);
        if((head == NULL) && (tail == NULL)){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    };

    void display(){
        Node* temp1 = head;
        while(temp1 != NULL){
            cout<<temp1->val<<"->";
            temp1 = temp1->next;
        }
    };


};

int main(){

    int n ;
    cin>>n;

    vector<int>v(n,0);

    for(int i=0;i<n;i++) cin>>v[i];


    LinkedList ll;
    
    for(int i=0 ; i<n ; i++){
        ll.insertAtTail(v[i]);
    };

    ll.display();



    return 0;


}