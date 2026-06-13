// Problem: Remove Nth Node From End of List
// Platform: NeetCode
// Link: https://neetcode.io/problems/remove-nth-node-from-end-of-list
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // dummy node — head remove হলেও handle করা যাবে
        // যেমন: list=[1], n=1 → head remove করতে হবে
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // fast আর slow দুইটাই dummy থেকে শুরু
        ListNode *fast = dummy;
        ListNode *slow = dummy;

        // fast কে n+1 step এগাও
        // n+1 কারণ slow কে remove করার node এর আগে রাখতে হবে
        // যেমন: n=2, list=1→2→3→4→5
        // fast: dummy→1→2→3 (3 step)
        for (int i = 0; i < n + 1; i++)
        {
            fast = fast->next;
        }

        // fast আর slow একসাথে এগাও
        // fast NULL হলে slow = remove করার node এর আগে
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // slow->next কে skip করো → remove হয়ে গেল
        slow->next = slow->next->next;

        // dummy->next = actual head
        return dummy->next;
    }
};