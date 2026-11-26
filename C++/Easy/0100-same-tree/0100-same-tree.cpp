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
    void traversal1(TreeNode*& p, vector<int>& tree1) {
        if (p == nullptr) {
            tree1.push_back(INT_MIN);
            return;
        }
        traversal1(p->left, tree1);
        traversal1(p->right, tree1);
        tree1.push_back(p->val);
    }
    void traversal2(TreeNode*& q, vector<int>& tree2) {
        if (q == nullptr) {
            tree2.push_back(INT_MIN);
            return;
        }
        traversal2(q->left, tree2);
        traversal2(q->right, tree2);
        tree2.push_back(q->val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> tree1;
        vector<int> tree2;
        traversal1(p, tree1);
        traversal2(q, tree2);
        return tree1 == tree2;
    }
};