/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (35.62%)
 * Likes:    2800
 * Dislikes: 182
 * Total Accepted:    433.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* root = new ListNode(0);
        ListNode* cur = root;
        while(lists.size() != 0)
        {
            if(lists.size() == 1)
            {
                cur->next = lists[0];
                break;
            }
            int min = 1000;
            int min_idx = 0;
            for(int i = 0;i<lists.size();i++)
            {
                if(lists[i] == NULL)
                {
                    lists.erase(lists.begin() + i);
                    i--;
                    if(lists.size() == 0)
                        break;
                    continue;
                }
                if(lists[i]->val < min)
                {
                    min = lists[i]->val;
                    min_idx = i;
                }
            }
            if(lists.size() == 0)
                break;
            cur->next = new ListNode(min);
            cur = cur->next;
            lists[min_idx] = lists[min_idx]->next;
            if(lists[min_idx] == NULL)
                lists.erase(lists.begin() + min_idx);
        }
        return root->next;
    }
};

