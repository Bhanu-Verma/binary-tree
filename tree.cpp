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

void print(node* root){
    
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}