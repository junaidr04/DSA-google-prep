// Problem: Linked List Cycle Detection
// Platform: NeetCode
// Link: https://neetcode.io/problems/linked-list-cycle-detection
// time complexity: O(n); where n is the number of nodes in the linked list
// space complexity: O(1); we are using only a constant amount of space to store the pointers



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
    bool hasCycle(ListNode *head)
    {

        // slow = একে একে এগায় (1 step)
        // fast = দুই দুই করে এগায় (2 steps)
        ListNode *slow = head, *fast = head;

        // fast == NULL মানে list শেষ → cycle নেই
        // fast->next == NULL মানে আর এগানো যাবে না → cycle নেই
        while (fast && fast->next)
        {
            slow = slow->next;       // 1 step
            fast = fast->next->next; // 2 steps

            // cycle থাকলে fast একসময় slow কে ধরে ফেলবে
            // মানে দুইজন same node এ থাকবে
            if (slow == fast)
            {
                return true; // cycle আছে
            }
        }
        return false;
    }
};