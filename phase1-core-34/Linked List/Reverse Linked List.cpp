// Problem: Reverse Linked List
// Platform: LeetCode
// Link: https://leetcode.com/problems/reverse-linked-list/description/
// time complexity: O(n)
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr)
        {
            // next save kora
            ListNode *next = curr->next;
            // curr->next ghuraw(prev a)
            curr->next = prev;
            // prev and curr agaii daw
            prev = curr;
            curr = next;
        }
        return prev;
    }
};