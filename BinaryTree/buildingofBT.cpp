#include <bits/stdc++.h>
using namespace std;

class node {
    public:
      int data;
      node* left ;
      node* right;

      node(int d){
          this-> data =d;
          this-> left = NULL;
          this-> right = NULL;

      }
};

node* buildTree(node* root){     // as it return a node*
   cout<< "Enter data" <<endl;
   int data;
   cin>> data;
   root = new node(data);

   if(data == -1){
    return NULL;
   }

   // enter for fisrt left 
   cout<< "Enter for insertiin of left node of "<<data<<endl;
   root->left = buildTree(root->left);

   cout<< "Enter for insertion of right node of "<<data<<endl;
   root->right = buildTree(root->right);

   return root;
}

int main(){
    // create a empty node at starting 
    node* root = NULL;

    // creating a tree
    root = buildTree(root);
    return 0;
}