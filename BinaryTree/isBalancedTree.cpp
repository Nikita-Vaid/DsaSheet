class Solution {
public:
    pair<bool, int> BalanceFast(TreeNode* root) {
        // base case
        if (root == nullptr) {
            return make_pair(true, 0);
        }

        pair<bool, int> left = BalanceFast(root->left);
        pair<bool, int> right = BalanceFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if (leftAns && rightAns && diff) {
            ans.first = true;
        } else {
            ans.first = false;
        }

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return BalanceFast(root).first;
    }
};
