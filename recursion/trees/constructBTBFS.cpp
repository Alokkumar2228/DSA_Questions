#include <bits/stdc++.h>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* QueueLevelTrav( int arr[],int n){
    queue<Node*>q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size()>0 && i<n){
        Node* temp = q.front();
        q.pop();
        Node* left ;
        Node* right ;
        if(i < n && arr[i] != INT_MIN){
            left = new Node(arr[i]);
        }else left = nullptr;
        if(j<n && arr[j] != INT_MIN){
            right = new Node(arr[j]);
        }else right = nullptr;

        if(left != nullptr){
            temp->left = left;
            q.push(left);
        };
        if(right!=nullptr){
            temp->right = right;
            q.push(right);
        };
        i+=2;
        j+=2;
    }

    return root;
}

int level(Node* root){
    if(root == nullptr)return 0;
    return (1 + max(level(root->left),level(root->right)));
}

void printLevelOrder(Node* root , int level , int var){
    if(root == nullptr) return;
    if(level == var)cout<<root->val<<" ";
    printLevelOrder(root->left , level , var+1);
    printLevelOrder(root->right , level , var+1);
}


int main() {
   
    int arr[] = {1,2,3,4,5,6,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = QueueLevelTrav(arr ,n);

    int root_level = level(root);
    
    for(int  i=1 ; i<=root_level ; i++){
        printLevelOrder(root , i , 1);
        cout<<endl;
    }
  

    return 0;
}


