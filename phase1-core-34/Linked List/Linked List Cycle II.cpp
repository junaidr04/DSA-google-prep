// Problem: Linked List Cycle II
// Platform: LeetCode
// Link: https://leetcode.com/problems/linked-list-cycle-ii/description/
// time complexity: O(n)
// space complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        // Part 1: cycle আছে কিনা দেখো
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // Part 2: cycle শুরু খোঁজো
                ListNode *start = head; // new pointer head theke
                while (start != slow)
                {
                    start = start->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};