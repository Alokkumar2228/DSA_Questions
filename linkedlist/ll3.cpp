// Printing list without using print function


// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int val;
//     Node* next;

//     Node(int val){
//         this->val = val;
//         this->next = NULL;
//     }
// };

// class LinkedList{
//     public:
//     Node* head ;
//     Node* tail;

//     LinkedList() {
//     head = tail = nullptr;
//      }

//     Node* insertAtEnd(int val){
//         Node* temp = new Node(val);
//         if(head == nullptr && tail == nullptr){
//             head = tail = temp;
//         }else{
//             tail->next = temp;
//             tail = temp;
//         }

//         return head;
//     }

// };

// int main(){

//     LinkedList ll;
//     Node* head = nullptr ;
//     for(int i=0 ; i<5 ; i++){
//         int n;
//         cin>>n;
//         head = ll.insertAtEnd(n);
//     }

//     Node* temp = head;
//     while(temp!=NULL){
//         cout<<temp->val<<"->";
//         temp = temp->next;
//     };



//     return 0;


// }

#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;  // ✅ Always initialize
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = tail = nullptr; // ✅ initialize empty list
    }

    void insertAtEnd(int val) {   // ✅ no return
        Node* temp = new Node(val);
        if (head == nullptr && tail == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void printList() {   // ✅ helper to print
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void midNode (){
        //Slow and  Fast Pointer techinque in linked list
        Node* prev = nullptr;
        Node* slow = head;
        Node* fast = head;

        while(fast!= nullptr && fast->next!=nullptr){
            if(prev == nullptr){
                prev = head;
            }else{
                prev = prev->next;
            }
            slow = slow->next;
            fast = fast->next->next;

        };

        prev->next = prev->next->next;

        
     
    };

    void PrintmidNode (){
        //Slow and  Fast Pointer techinque in linked list
        Node* slow = head;
        Node* fast = head;

        while(fast!= nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;

        };

        cout<<slow->val;
     
    };


    void deleteMidNode (){
        //Slow and  Fast Pointer techinque in linked list
        Node* prev = nullptr;
        Node* slow = head;
        Node* fast = head;

        while(fast!= nullptr && fast->next!=nullptr){
            if(prev == nullptr){
                prev = head;
            }else{
                prev = prev->next;
            }
            slow = slow->next;
            fast = fast->next->next;

        };

        prev->next = prev->next->next;      
     
    };



    void printNode(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
    };

    // Remove nth node from end in linked list -> use slow and fast pointer technique
    // 1. for deleteing the slow should be one node behind the node which we have to delete
    // 2. so make fast n+1 node ahead of slow where n is the number of position from last to delete
    //but for printing nth node from end make fast n node ahead of slow

    void deltenthNodefromEnd(int n){
        Node* fast = head;
        Node* slow = head;

        for(int i=1 ; i<=n+1 ; i++){
            fast = fast->next;
        };

        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
        };

        slow->next = slow->next->next;

    }

    void printNthNodefromEnd(int n){
        Node* fast = head;
        Node* slow = head;

        for(int i=1 ; i<=n ; i++){
            fast = fast->next;
        };

        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
        };

        cout << slow->val<<endl;

    }

    


};

int main() {
    LinkedList ll;
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        ll.insertAtEnd(n);
    }

    ll.printList();  // ✅ print directly

    ll.printNthNodefromEnd(2);

    ll.deltenthNodefromEnd(2);

    // ll.midNode();

    ll.printNode();

    





    return 0;
}
