// Problem: Merge Two Sorted Lists
// Platform: LeetCode
// Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
// time complexity: O(m+n)
// space complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // ekta dummy node lgbe..Result list কোথা থেকে শুরু সেটা track করতে!
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                // list1 এর node জুড়ে দাও
                curr->next = list1;
                // list1 এগিয়ে দাও
                list1 = list1->next;
            }
            else
            {
                // list2 এর node জুড়ে দাও
                curr->next = list2;
                // list2 এগিয়ে দাও
                list2 = list2->next;
            }
            // curr এগিয়ে দাও
            curr = curr->next;
        }
        // কোনো একটা list এখনো বাকি থাকতে পারে
        if (list1)
        {
            curr->next = list1;
        }
        else
        {
            curr->next = list2;
        }
        return dummy->next;
    }
};
