// Problem: Reorder Linked List
// Platform: NeetCode
// Link: https://neetcode.io/problems/reorder-list
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

class Solution {
public:
    // Helper 1 — Middle node খোঁজো
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // loop শেষে slow = middle node
        return slow;
    }
    
    // Helper 2 — List reverse করো
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;  // new head
    }
    
    void reorderList(ListNode* head)
    {
        // Step 1 — Middle খোঁজো
        ListNode* mid = findMid(head);
        
        // Step 2 — Second half reverse করো
        // mid থেকে reverse → mid->next = NULL হয়ে যাবে
        ListNode* list2 = reverseList(mid);
        ListNode* list1 = head;
        
        // Step 3 — দুই half merge করো
        // list1 থেকে একটা, list2 থেকে একটা করে নাও
        while(list2)
        {
            ListNode* tmp1 = list1->next;  // list1 এর next save
            ListNode* tmp2 = list2->next;  // list2 এর next save
            list1->next = list2;           // list1 এর পরে list2 জুড়ো
            list2->next = tmp1;            // list2 এর পরে list1 এর next জুড়ো
            list1 = tmp1;                  // list1 এগাও
            list2 = tmp2;                  // list2 এগাও
        }
        
        // odd length list এ middle node duplicate হয়
        // শেষ node এর next = null করো
        if(list1)
            list1->next = nullptr;
    }
};
