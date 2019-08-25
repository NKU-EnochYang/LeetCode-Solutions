/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (48.47%)
 * Likes:    2523
 * Dislikes: 365
 * Total Accepted:    654.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode(0);
        ListNode* res = root;
        while(l1 || l2)
        {
            if(l1 && l2)
            {
                if(l1->val < l2->val)
                {
                    res->next = new ListNode(l1->val);
                    l1 = l1->next;
                }
                else
                {
                    res->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
                res = res->next;
            }
            if(l1 && !l2)
            {
                res->next = l1;
                break;
            }
            if(l2 && !l1)
            {
                res->next = l2;
                break;
            }
        }
        return root->next;
    }
};

