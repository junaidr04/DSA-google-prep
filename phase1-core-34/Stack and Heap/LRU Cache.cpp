// Problem: LRU Cache
// Platform: LeetCode
// Link: https://leetcode.com/problems/lru-cache/description/
// time complexity: O(1)
// space complexity: O(capacity)

struct Node
{
    int key, val;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};
class LRUCache
{
    int cap;
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;

    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void insert(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity)
    {
        // cap set করো
        cap = capacity;
        // dummy head আর tail বানাও
        head = new Node(0, 0); // most recent এর আগে
        tail = new Node(0, 0); // least recent এর পরে
        // head ↔ tail connect করো
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        // key map এ নেই
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            // map theke node naw
            Node *node = mp[key];
            // node টা remove করো (current position থেকে)
            remove(node);
            // node টা insert করো (HEAD এর পাশে)
            insert(node);
            // value return করো
            return node->val;
        }
    }
    void put(int key, int value)
    {
        // key already exist করলে
        if (mp.find(key) != mp.end())
        {
            // map থেকে node নাও
            // list থেকে remove করো
            remove(mp[key]);
            // map থেকেও delete করো
            delete mp[key];
            mp.erase(key);
        }

        // capacity full হলে
        if (mp.size() == cap)
        {
            // tail এর আগের node (LRU) বাদ দাও
            Node *lru = tail->prev;
            remove(lru);
            // map থেকেও delete করো
            mp.erase(lru->key);
            delete lru;
        }
        // নতুন node বানাও →
        Node *newNode = new Node(key, value);
        // HEAD এর পাশে insert করো
        insert(newNode);
        // map এ রাখো
        mp[key] = newNode;
    }
};