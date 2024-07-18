// Depth first traversal has Three types 1. inorder 2. preorder 3. postorder 


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


void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);  // Marker for level end

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {  // Level end
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);  // Marker for the next level end
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void InoderTraversal ( node* root ){    // LNR
    // base case 
    if( root == NULL){
      return;
    }

    // left
    InoderTraversal(root->left);
    // node 
    cout<< root->data << " ";
    // right
     InoderTraversal(root->right);

}
void PreoderTraversal ( node* root ){    // NLR
    // base case 
    if( root == NULL){
      return;
    }

    // node 
    cout<< root->data << " ";
    // left
    PreoderTraversal (root->left);
    // right
    PreoderTraversal(root->right);

}
void PostoderTraversal ( node* root ){    // LRN
    // base case 
    if( root == NULL){
      return;
    }

    // left
    PostoderTraversal (root->left);
    // right
    PostoderTraversal(root->right);
    // node 
    cout<< root->data << " ";

}


int main(){
   // Create an empty node at starting
    node* root = NULL;

    // Creating a tree
    root = buildTree(root);

    // Level order Traversal
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

     // Inorder Traversal
    cout <<endl << "Inorder Traversal: " << endl;
     InoderTraversal(root);

     // Preorder Traversal
    cout <<endl << "Preorder Traversal: " << endl;
     PreoderTraversal(root);

      // Postorder Traversal
    cout <<endl << "Postorder Traversal: " << endl;
     PostoderTraversal(root);

    return 0;
}


// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 