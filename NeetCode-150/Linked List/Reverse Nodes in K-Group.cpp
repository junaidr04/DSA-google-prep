// Problem: Reverse Nodes in K-Group
// Platform: NeetCode
// Link: https://neetcode.io/problems/reverse-nodes-in-k-group
// time complexity: O(n) where n is the total number of nodes
// space complexity: O(1) for iterative approach or O(k) for recursive approach

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
    // Helper: currNode থেকে k ধাপ এগিয়ে kth node return করো
    // যদি k-এর কম node থাকে → null return হবে
    ListNode *kthN(ListNode *curr, int k)
    {
        while (curr && k > 0) // k বার এগোবো, অথবা list শেষ হলে থামবো
        {
            curr = curr->next; // এক ধাপ এগোও
            k--;               // কাউন্টার কমাও
        }
        return curr; // kth node (বা null যদি কম node থাকে)
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Dummy node বানাও — head change হলেও dummy ধরে রাখবে শুরুটা
        ListNode *dummy = new ListNode(0);
        dummy->next = head; // dummy কে real list এর আগে জুড়ে দাও

        ListNode *prevGrp = dummy; // prevGrp = current group এর ঠিক আগের node

        while (true)
        {
            // prevGrp থেকে k ধাপ এগিয়ে kth node খোঁজো
            ListNode *kth = kthN(prevGrp, k);

            // kth null মানে k-এর কম node বাকি → আর reverse করবো না
            if (kth == nullptr)
                break;

            ListNode *grpstrt = prevGrp->next; // current group এর 1st node
                                               // (reverse এর পর এটা last হবে)
            ListNode *grpnxt = kth->next;      // next group এর 1st node
                                               // (এখানে এসে reversal থামবে)

            // ── Reversal শুরু ──
            ListNode *prev = grpnxt;  // KEY: last node টা grpnxt কে point করবে
                                      // তাই prev = grpnxt দিয়ে শুরু
            ListNode *curr = grpstrt; // curr = group এর শুরু থেকে চলবে

            while (curr != grpnxt) // শুধু এই group এর মধ্যে থাকবো
            {
                ListNode *tmp = curr->next; // পরের node save করো (হারিয়ে যাবে নাহলে)
                curr->next = prev;          // pointer উল্টে দাও
                prev = curr;                // prev এক ধাপ এগোলো
                curr = tmp;                 // curr এগোলো (saved next এ)
            }
            // এখন prev = kth (group এর new head)
            // ── Reversal শেষ ──

            // ── Connections ──
            prevGrp->next = kth;    // আগের part → reversed group এর new head
            grpstrt->next = grpnxt; // reversed group এর tail → পরের group

            // পরের iteration এর জন্য prevGrp সরাও
            // grpstrt এখন last position এ, তাই সে হবে পরের group এর "আগের node"
            prevGrp = grpstrt;
        }

        return dummy->next; // dummy এর পরেই real answer শুরু
    }
};