#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node *next=NULL;

    Node(int val){
        this->val = val;
    };


};

// void display(Node *a){  // in this we using the another pointer to traverse the linked list
//     Node *head = a;
//     while(head != NULL){
//         cout<<head->val <<"->";
//         head = head->next;
//     }
// };

void display(Node *head){   // head ek nya daba bana jo a ko point karega
    while(head != NULL){
        cout<<head->val <<"->";
        head = head->next;
    }
};


int main(){

    // Node a(10);
    // Node b(20);
    // Node c(30);
    // Node d(40);


    // a.next = &b;
    // b.next = &c;
    // c.next = &d;

    // Node *head = &a;

    // while(head!= NULL){
    //     cout<< head->val<<"->";
    //     head = head->next;
    // };

    // cout<< (a.next)->val << endl; // ans 20

    //Note -> *(a.next).val is same as (a.next)->val

    // cout<< (a.next)->next->next->val <<endl; //ans 40

    // Node *a = new Node(100);
    // Node *b = new Node(200);
    // Node *c = new Node(300);
    // Node *d = new Node(400);
    // Node *e = new Node(500);

    // a->next = b;
    // b->next = c;
    // c->next = d;
    // d->next = e;

    // display(a);

    Node* a = new Node(5);
    Node* b = new Node(5);

    if (a == b) {
        cout << "Same node\n";
    } else {
        cout << "Different nodes\n";
    };
    


   




    return 0;
}