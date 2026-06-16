// Problem: LRU Cache
// Platform: NeetCode
// Link: https://neetcode.io/problems/lru-cache
// time complexity: O(1) for get and put operations
// space complexity: O(capacity); where capacity is the maximum number of elements that can be stored in the cache



// ধারণা:
// ১. unordered_map ব্যবহার করে O(1) সময়ে key খুঁজে বের করা হয়।
// ২. Doubly Linked List ব্যবহার করে O(1) সময়ে node insert/delete করা হয়।
//
// Linked List এ:
// head-এর পরের node = সবচেয়ে Recently Used (MRU)
// tail-এর আগের node = সবচেয়ে Least Recently Used (LRU)


struct Node
{
    int key, val; // key ও value সংরক্ষণ করবে
    Node *prev;   // আগের node-এর address
    Node *next;   // পরের node-এর address

    // Constructor
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{

    int cap; // Cache-এর সর্বোচ্চ capacity

    // key -> node address
    unordered_map<int, Node *> mp;

    // Dummy head ও tail node
    Node *head;
    Node *tail;

    // Linked List থেকে একটি node remove করার function
    void remove(Node *node)
    {
        // node-এর আগের node-কে node-এর পরের node-এর সাথে connect করি
        node->prev->next = node->next;

        // node-এর পরের node-কে node-এর আগের node-এর সাথে connect করি
        node->next->prev = node->prev;
    }

    // Node-কে head-এর পরে insert করি
    // অর্থাৎ এটি সবচেয়ে Recently Used node হবে
    void insert(Node *node)
    {
        // নতুন node-এর next হবে head-এর পরের node
        node->next = head->next;

        // নতুন node-এর prev হবে head
        node->prev = head;

        // আগের প্রথম node-এর prev নতুন node-এর দিকে point করবে
        head->next->prev = node;

        // head এখন নতুন node-কে point করবে
        head->next = node;
    }

public:
    // Constructor
    LRUCache(int capacity)
    {
        cap = capacity;

        // Dummy head ও tail তৈরি
        head = new Node(0, 0);
        tail = new Node(0, 0);

        // শুরুতে list হবে:
        // head <-> tail

        head->next = tail;

        // এখানে BUG আছে
        // হওয়া উচিত:
        // tail->prev = head;
        tail->next = head;
    }

    int get(int key)
    {
        // key না থাকলে
        if (mp.find(key) == mp.end())
        {
            return -1;
        }

        // key পাওয়া গেলে
        Node *node = mp[key];

        // বর্তমান position থেকে remove করি
        remove(node);

        // সামনে নিয়ে আসি (Recently Used)
        insert(node);

        // value return করি
        return node->val;
    }

    void put(int key, int value)
    {
        // key আগে থেকেই থাকলে
        if (mp.find(key) != mp.end())
        {
            // পুরোনো node remove করি
            remove(mp[key]);

            // memory free করি
            delete mp[key];

            // hashmap থেকে delete করি
            mp.erase(key);
        }

        // Cache full হলে
        if (mp.size() == cap)
        {
            // tail-এর আগের node হলো LRU
            Node *lru = tail->prev;

            // List থেকে remove
            remove(lru);

            // hashmap থেকে remove
            mp.erase(lru->key);

            // memory free
            delete lru;
        }

        // নতুন node তৈরি
        Node *newNode = new Node(key, value);

        // সামনে insert করি
        insert(newNode);

        // hashmap-এ রাখি
        mp[key] = newNode;
    }
};