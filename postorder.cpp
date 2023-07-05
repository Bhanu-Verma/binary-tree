#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=this->right=NULL;
    }
};

node* buildTree(node* root){
        int x;
        cout<<"enter the data to place:";
        cin>>x;
        root= new node(x);
        if(x==-1){
            return NULL;
        }

        
        cout<<"insert to left of "<<x<<endl;
        root->left=buildTree(root->left);
        cout<<"insert to right of "<<x<<endl;
        root->right=buildTree(root->right);
        return root;
} 

void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    
    postorder(root->right);
    cout<<root->data<<" ";
}


int main(){
    node* root=NULL;
    root=buildTree(root);

    cout<<"\n\n\n";
    postorder(root);
    return 0;
}