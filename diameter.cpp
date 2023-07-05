#include <bits/stdc++.h>
using namespace std;
#include "tree.cpp"



int height(node* root){
    if(root==NULL){
        return 0;
    }

    return 1+max(height(root->left),height(root->right));
}
// diameter of tree in O(n2)
int diameter(node* root){
    if(root==NULL){
        return 0;

    }
    int a=diameter(root->left);
    int b=diameter(root->right);
    
    return max(max(a,b),height(root->left)+1+height(root->right));
}

// diameter of tree in O(n)
// here at every call we will return a pair of int. In that pair first will be dia and second
//will be height
// thus we can avoid O(n2)

pair<int,int> fastdia(node* root){
    if(root==NULL){
       pair<int,int> p=make_pair(0,0);
       return p;
    }

    pair<int,int> left=fastdia(root->left);
    pair<int,int> right=fastdia(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;

    pair<int,int> ans=make_pair(max(max(op1,op2),op3),max(left.second,right.second)+1);
    return ans;
}



int main(){
    node* root=NULL;
    root=buildTree(root);
    int x=diameter(root);
    cout<<x<<endl;
    pair<int,int> y=fastdia(root);
    cout<<y.first<<endl;
    return 0;
}
