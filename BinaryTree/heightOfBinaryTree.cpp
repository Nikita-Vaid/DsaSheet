#include <iostream>
#include <algorithm> // for std::max

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return std::max(left, right) + 1;
    }
};

// Helper function to create a new tree node
TreeNode* newNode(int data) {
    TreeNode* node = new TreeNode(data);
    node->left = nullptr;
    node->right = nullptr;
    return(node);
}

// Driver code
int main() {
    Solution solution;

    // Creating a sample binary tree
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    std::cout << "Max depth of the binary tree: " << solution.maxDepth(root) << std::endl;

    return 0;
}
