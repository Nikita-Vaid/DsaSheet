// O(n)

class Solution {
public:

    pair<int, int> diameterFast(TreeNode* root) {
        // base case
        if (root == nullptr) {
            return make_pair(0, 0);
        }

        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second;

        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3)); // diameter
        ans.second = max(left.second, right.second) + 1; // height
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }
};
