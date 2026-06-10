// Problem: Reverse Linked List
// Platform: NeetCode
// Link: https://neetcode.io/problems/reverse-linked-list
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
    ListNode *reverseList(ListNode *head)
    {

        // prev = reversed অংশের head
        // শুরুতে কিছু নেই → NULL
        ListNode *prev = NULL;

        // curr = এখন যে node এ আছি
        ListNode *curr = head;

        while (curr)
        {
            // আগে next save করো
            // না হলে curr->next = prev করার পর
            // original next হারিয়ে যাবে
            ListNode *next = curr->next;

            // curr এর next কে উল্টো দিকে point করাও
            curr->next = prev;

            // prev এক ধাপ এগাও
            prev = curr;

            // curr এক ধাপ এগাও
            curr = next;
        }

        // curr = NULL মানে list শেষ
        // prev = নতুন head
        return prev;
    }
};