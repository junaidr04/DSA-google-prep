// Problem: Copy Linked List with Random Pointer
// Platform: NeetCode
// Link: https://neetcode.io/problems/copy-list-with-random-pointer
// time complexity: O(n); where n is the number of nodes in the linked list
// space complexity: O(1); we are using only a constant amount of space to store the pointers


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // old node → new node mapping
        // এই map দিয়ে next আর random pointer set করবো
        unordered_map<Node *, Node *> mp;

        // Loop 1 — প্রতিটা node এর copy বানাও
        // শুধু value copy করো, pointer এখনো set করো না
        Node *curr = head;
        while (curr)
        {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Loop 2 — next আর random pointer set করো
        curr = head;
        while (curr)
        {
            // curr->next এর copy = mp[curr->next]
            // curr->next NULL হলে mp[NULL] = NULL → ঠিক আছে
            mp[curr]->next = mp[curr->next];

            // curr->random এর copy = mp[curr->random]
            // random NULL হলে mp[NULL] = NULL → ঠিক আছে
            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        // head এর copy = mp[head]
        return mp[head];
    }
};