// Problem: Merge K Sorted Linked Lists
// Platform: NeetCode
// Link: https://neetcode.io/problems/merge-k-sorted-lists
// time complexity: O(n log k) where n is the total number of nodes and k is the number of lists
// space complexity: O(k) for the priority queue


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

    // Custom Comparator
    // Priority Queue-কে Min Heap বানানোর জন্য ব্যবহার করা হয়েছে
    struct compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            // যার value বড়, তাকে lower priority দাও
            // ফলে সবচেয়ে ছোট value top-এ থাকবে
            return a->val > b->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        // Min Heap তৈরি
        // এখানে সব list-এর current smallest node থাকবে
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;

        // প্রতিটি linked list-এর প্রথম node heap-এ insert করি
        for (auto node : lists)
        {
            if (node) // list খালি না হলে
            {
                pq.push(node);
            }
        }

        // Result list তৈরির জন্য dummy node
        ListNode *dummy = new ListNode(0);

        // Result list build করার pointer
        ListNode *curr = dummy;

        // যতক্ষণ heap খালি না হয়
        while (!pq.empty())
        {
            // সবচেয়ে ছোট value-এর node বের করি
            ListNode *top = pq.top();
            pq.pop();

            // Result list-এর শেষে যোগ করি
            curr->next = top;

            // curr এক ধাপ সামনে নিয়ে যাই
            curr = curr->next;

            // যদি popped node-এর পরে আর node থাকে
            if (top->next)
            {
                // পরের node heap-এ push করি
                pq.push(top->next);
            }
        }

        // Dummy node বাদ দিয়ে আসল head return করি
        return dummy->next;
    }
};