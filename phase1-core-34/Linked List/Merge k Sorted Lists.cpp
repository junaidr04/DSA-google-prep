// Problem: Merge k Sorted Lists
// Platform: LeetCode
// Link: https://leetcode.com/problems/merge-k-sorted-lists/description/
// time complexity: O(n log k)
// space complexity: O(k)

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
    struct compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for (auto node : lists)
        {
            if (node) // node null na hole
            {
                pq.push(node);
            }
        }
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (!pq.empty())
        {
            // top naw
            ListNode *top = pq.top();
            pq.pop();
            // atach with result
            curr->next = top;
            curr = curr->next;
            // top er next heap a daw
            if (top->next) // top->next null na hole
            {
                pq.push(top->next);
            }
        }
        return dummy->next;
    }
};