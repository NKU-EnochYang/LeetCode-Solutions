/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (49.71%)
 * Likes:    1720
 * Dislikes: 44
 * Total Accepted:    421.2K
 * Total Submissions: 845.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
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
    void getLvNodeNum(TreeNode *cur, vector<int> &nums, int depth)
    {
        if (cur == NULL)
            return;
        nums[depth]++;
        getLvNodeNum(cur->left, nums, depth + 1);
        getLvNodeNum(cur->right, nums, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        TreeNode *cur = root;
        vector<TreeNode *> que;
        que.push_back(root);
        for (int i = 0; i < que.size(); i++)
        {
            cur = que[i];
            if (cur->left != NULL)
                que.push_back(cur->left);
            if (cur->right != NULL)
                que.push_back(cur->right);
        }
        vector<int> nums(que.size(), 0);
        getLvNodeNum(root, nums, 0);
        int pq = 0;
        for (int i = 0; i < nums.size() && nums[i] != 0; i++)
        {
            vector<int> temp;
            for (int j = pq; j < pq + nums[i]; j++)
                temp.push_back(que[j]->val);
            pq += nums[i];
            res.push_back(temp);
        }
        return res;
    }
};
