// 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/solutions/
// bfs tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            long long int sum = 0;
            double len = nodes.size();
            for (int i = 0; i < len; i++) {
                TreeNode* first = nodes.front();
                sum += first->val;
                nodes.pop();
                if (first->left)
                    nodes.push(first->left);
                if (first->right)
                    nodes.push(first->right);
            }
            double s = sum / len;
            ans.push_back(s);
        }
        return ans;
    }
};