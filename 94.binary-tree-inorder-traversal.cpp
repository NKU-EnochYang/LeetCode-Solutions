/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (57.97%)
 * Likes:    1879
 * Dislikes: 81
 * Total Accepted:    513.6K
 * Total Submissions: 883.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        vector<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur != NULL || !stk.empty())
        {
            while (cur != NULL)
            {
                stk.push_back(cur);
                cur = cur->left;
            }
            cur = stk.back();
            stk.pop_back();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }
};
