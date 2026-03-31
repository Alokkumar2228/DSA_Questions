#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = right = nullptr;
    }
};

TreeNode* buildBinaryTree(vector<int>&v , int len , int idx){

    if(idx>=len)return nullptr;
    TreeNode* root = new TreeNode(v[idx]);
    root->left = buildBinaryTree(v , len , 2*idx+1);
    root->right = buildBinaryTree(v , len , 2*idx+2);
    return root;

};

void preOrder(TreeNode* root){
    if(!root)return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
};



int main(){

    vector<int>v = {1,2,3,4,5,6,7};
    int n = v.size();
    TreeNode* root = buildBinaryTree(v , n , 0);
    preOrder(root);


    return 0;
}

