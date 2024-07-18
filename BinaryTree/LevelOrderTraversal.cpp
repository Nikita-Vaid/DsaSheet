// Breadth First Search or BFS for a Graph

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


int main(){
   // Create an empty node at starting
    node* root = NULL;

    // Creating a tree
    root = buildTree(root);

    // Level order Traversal
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);


    return 0;
}


// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 