// Problem: Merge Two Sorted Linked Lists
// Platform: NeetCode
// Link: https://neetcode.io/problems/merge-two-sorted-linked-lists
// time complexity: O(n + m); where n and m are the number of nodes in the two linked lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        // dummy node — head change হলেও সহজে handle করা যাবে
        // dummy->next = merged list এর actual head
        ListNode *dummy = new ListNode(0);

        // curr = merged list এর current end
        ListNode *curr = dummy;

        // দুই list এই চলতে থাকো
        while (list1 && list2)
        {
            // list1 এর value ছোট → list1 থেকে নাও
            if (list1->val < list2->val)
            {
                curr->next = list1;  // curr এর পরে list1 জুড়ো
                list1 = list1->next; // list1 এগাও
            }
            else
            {
                // list2 এর value ছোট বা সমান → list2 থেকে নাও
                curr->next = list2;  // curr এর পরে list2 জুড়ো
                list2 = list2->next; // list2 এগাও
            }

            // curr এগাও — নতুন node এর পরে জুড়তে হবে
            curr = curr->next;
        }

        // একটা list শেষ হয়ে গেছে
        // বাকি list টা সরাসরি জুড়ে দাও
        if (list1)
            curr->next = list1;
        else
            curr->next = list2;

        // dummy->next = merged list এর head
        return dummy->next;
    }
};