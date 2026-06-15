// Problem: Add Two Numbers
// Platform: NeetCode
// Link: https://neetcode.io/problems/add-two-numbers
// time complexity: O(max(n, m)); where n and m are the number of nodes in the two linked lists
// space complexity: O(max(n, m)); we are creating a new linked list to store the result, which in the worst case can have max(n, m) + 1 nodes (if there is a carry at the end)


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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // carry = আগের digit থেকে যা বেঁচে আছে
        int carry = 0;

        // dummy node — result list এর head হবে dummy->next
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        // l1 বা l2 বা carry যেকোনো একটা থাকলে loop চলবে
        // carry থাকলে extra node লাগতে পারে
        // যেমন: 9+9=18 → node(8), carry=1 → extra node(1)
        while (l1 || l2 || carry)
        {
            // sum শুরু হয় carry দিয়ে
            int sum = carry;

            // l1 এর digit যোগ করো, তারপর এগাও
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            // l2 এর digit যোগ করো, তারপর এগাও
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            // পরের digit এ carry হবে কত
            // যেমন: sum=17 → carry=1
            carry = sum / 10;

            // শুধু last digit টা node এ রাখো
            // যেমন: sum=17 → node(7)
            curr->next = new ListNode(sum % 10);

            // পরের node এ যাও
            curr = curr->next;
        }

        // dummy->next = result list এর actual head
        return dummy->next;
    }
};
