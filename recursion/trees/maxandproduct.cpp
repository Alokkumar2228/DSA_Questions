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
void Sum(Node* root, int &ans) {
    if (root == nullptr) return;
    ans += root->val;
    Sum(root->left, ans);
    Sum(root->right, ans);
}

void printLevel(Node)


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
    int ans = 0;
    Sum(root , ans);
    cout<<ans;

    // cout << "Maximum value in tree: " << maxVal(root)<<endl;
    // cout<<height(root);

    return 0;
}
