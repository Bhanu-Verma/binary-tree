#include <bits/stdc++.h>
using namespace std;
// height--- longest path between root and the leaf node
#include "tree.cpp"


int height(node* root){
    if(root==NULL){
        return 0;
    }

    return 1+max(height(root->left),height(root->right));
}

int main(){
     node* root=NULL;
    root=buildTree(root);
    int h=height(root);
    cout<<h<<endl;
    
    return 0;
}