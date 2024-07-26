#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node ( int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }

};

Node* insertinToBST(Node *root, int data){
   // base case
   if( root = NULL){
        root = new Node(data);
        return root;
   }

   if( data > root->data ){
    // right part me dalo
    root->right = insertinToBST(root->right, data);
   }
   else{
    // left part me dalo 
    root->left = insertinToBST( root->right, data);
   }
   return root;
}

void takeInput(Node *root){
    int data;
    cin>> data;

    while( data != -1){
       root = insertinToBST(root, data);
       cin>> data;
    }

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

    Node* root = NULL;

    cout<< "Enter data to craete BST: "<<endl;
    takeInput();

    cout<< "Print BST" << endl;
    levelOrderTraversal(root);

    return 0;
}