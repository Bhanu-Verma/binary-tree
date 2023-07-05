#include <bits/stdc++.h>
using namespace std;
#include "tree.cpp"

pair<bool,int> isBalanced(node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }

        bool left=isBalanced(root->left).first;
        bool right=isBalanced(root->right).first;
        int h1=isBalanced(root->left).second;
        int h2=isBalanced(root->right).second;
        pair<bool,int> ans=make_pair(left && right && (abs(h1-h2)<=1), max(h1,h2)+1);
        return ans;
}

int main(){
    node* root=NULL;
    buildTree(root);
    if(isBalanced(root).first){
        cout<<"tree is balanced.\n";
    }else{
        cout<<"tree is not balanced.\n";
    }

    return 0;
}