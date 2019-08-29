/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.12%)
 * Likes:    2569
 * Dislikes: 55
 * Total Accepted:    448.9K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    TreeNode *getMirror(TreeNode *ori, TreeNode *mir)
    {
        if (ori == NULL)
            return mir;
        mir = new TreeNode(ori->val);
        if (ori->left != NULL)
            mir->right = getMirror(ori->left, mir->right);
        if (ori->right != NULL)
            mir->left = getMirror(ori->right, mir->left);
        return mir;
    }
    bool compareTwoTree(TreeNode *tree1, TreeNode *tree2)
    {
        if (tree1 == NULL && tree2 == NULL)
            return true;
        if (tree1 == NULL && tree2 != NULL)
            return false;
        if (tree1 != NULL && tree2 == NULL)
            return false;
        if (tree1->val != tree2->val)
            return false;
        return compareTwoTree(tree1->left, tree2->left) &&
               compareTwoTree(tree1->right, tree2->right);
    }
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *mir = getMirror(root, NULL);
        return compareTwoTree(root, mir);
    }
};
