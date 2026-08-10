// Problem: Implement Trie (Prefix Tree)
// Platform: NeetCode
// Link: https://neetcode.io/problems/implement-trie-prefix-tree
// time complexity: O(L); L = length of the word
// space complexity: O(N * L); N = number of nodes, L = average length of words

class TrieNode
{
public:
    TrieNode *child[26]; // 26-টা pointer — a-z প্রতিটা character-এর জন্য child node
    bool isWordEnd;      // এই node-এ কোনো word শেষ হয়েছে কিনা তার flag

    TrieNode()
    {
        isWordEnd = false; // নতুন node মানে এখনো কোনো word শেষ হয়নি এখানে
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr; // শুরুতে সব child empty (কোনো path তৈরি হয়নি)
        }
    }
};

class PrefixTree
{
public:
    TrieNode *root; // পুরো trie-এর entry point — কোনো character represent করে না, শুধু শুরুর বিন্দু

    PrefixTree()
    {
        root = new TrieNode(); // Trie তৈরি হওয়ার সাথে সাথে একটা empty root node বানিয়ে ফেলি
    }

    void insert(string word)
    {
        TrieNode *curr = root; // root থেকে traversal শুরু
        for (char c : word)
        {
            int index = c - 'a'; // character কে 0-25 index-এ রূপান্তর
            // এই character-এর জন্য child না থাকলে নতুন node বানাও
            if (curr->child[index] == nullptr)
            {
                curr->child[index] = new TrieNode();
            }
            // pointer কে পরের node-এ move করো (path ধরে এগিয়ে যাওয়া)
            curr = curr->child[index];
        }
        // পুরো word বসানো শেষ — এখন curr শেষ character-এর node-এ আছে
        // এখানেই mark করি যে এই node-এ একটা সম্পূর্ণ word শেষ হয়েছে
        curr->isWordEnd = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            int index = c - 'a';
            // এই character-এর path না থাকলে word trie-তে নেই — সাথে সাথে false
            if (curr->child[index] == nullptr)
            {
                return false;
            }
            curr = curr->child[index]; // পরের node-এ move
        }

        // পুরো path পাওয়া গেছে, কিন্তু path থাকা মানেই word থাকা না
        // (যেমন "card" insert থাকলে "car"-এর path-ও exist করবে,
        //  কিন্তু "car" আলাদা word হিসেবে insert না থাকলে isWordEnd false-i থাকবে)
        // তাই আসল answer নির্ভর করে শেষ node-এর isWordEnd flag-এর উপর
        return curr->isWordEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (char c : prefix)
        {
            int index = c - 'a';
            if (curr->child[index] == nullptr)
            {
                return false;
            }
            curr = curr->child[index];
        }
        // এখানে search-এর মতো isWordEnd চেক করার দরকার নেই —
        // prefix মানে শুধু path থাকলেই যথেষ্ট প্রমাণ যে এই দিয়ে কিছু word শুরু হয়
        return true;
    }
};