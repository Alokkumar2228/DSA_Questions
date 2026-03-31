#include <bits/stdc++.h>
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

// Helper function to find maximum value in a binary tree
int maxVal(Node* root) {
    if (root == nullptr) return INT_MIN; // base case
    int leftMax = maxVal(root->left);
    int rightMax = maxVal(root->right);
    return max(root->val, max(leftMax, rightMax));
}

int height(Node* root){
    if(root == nullptr)return 0;
    int leftlevel = 1 + height(root->left);
    int rightlevel = 1 + height(root->right);
    return max(leftlevel , rightlevel);
}

int main() {
    Node* root = new Node(1);
    Node* n1 = new Node(2);
    Node* n2 = new Node(3);
    Node* n3 = new Node(4);
    Node* n4 = new Node(5);
    Node* n5 = new Node(6);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->right = n5;

    cout << "Maximum value in tree: " << maxVal(root)<<endl;
    cout<<height(root);

    return 0;
}
