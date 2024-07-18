// build tree from level oredr traversal 

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree() {
    cout << "Enter data" << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    node* root = new node(data);
    cout << "Enter for insertion of left node of " << data << endl;
    root->left = buildTree();
    cout << "Enter for insertion of right node of " << data << endl;
    root->right = buildTree();

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

void buildFromLevelOT(node*& root) {
    queue<node*> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;

    if (data == -1) {
        root = NULL;
        return;
    }

    root = new node(data);
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1) {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter right node for " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1) {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

int main() {
    node* root = NULL;


    // Building tree from level order traversal input
    cout << "Build from level order traversal:" << endl;
    node* levelOrderRoot = NULL;
    buildFromLevelOT(levelOrderRoot);

    // Level order Traversal of the new tree
    cout << "Level Order Traversal of the new tree: " << endl;
    levelOrderTraversal(levelOrderRoot);

    return 0;
}



// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 