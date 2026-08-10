// Problem: Design Add and Search Word Data Structure
// Platform: NeetCode
// Link: https://neetcode.io/problems/design-add-and-search-words-data-structure
// time complexity: O(L); L = length of the word
// space complexity: O(N * L); N = number of nodes, L = average length of words

class TrieNode
{
public:
    // প্রতিটি node থেকে 26টা possible character যেতে পারে
    // child[0] = 'a'
    // child[1] = 'b'
    // ...
    // child[25] = 'z'
    TrieNode *child[26];
    // এই node পর্যন্ত এসে কোনো complete word শেষ হয়েছে কিনা
    bool isWord;
    TrieNode()
    {
        // শুরুতে এই node কোনো word-এর শেষ নয়
        isWord = false;
        // শুরুতে কোনো child node নেই
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};

class WordDictionary
{
public:
    // Trie-এর starting/root node
    TrieNode *root;

    WordDictionary()
    {
        // শুরুতে একটি empty root তৈরি করি
        root = new TrieNode();
    }

    // =========================
    // ADD WORD
    // =========================
    void addWord(string word)
    {
        // root থেকে শুরু করছি
        TrieNode *curr = root;
        // word-এর প্রতিটি character এক এক করে দেখি
        for (char c : word)
        {
            // character কে 0-25 index এ convert করি
            // 'a' - 'a' = 0
            // 'b' - 'a' = 1
            // 'c' - 'a' = 2
            // ...
            // 'z' - 'a' = 25
            int index = c - 'a';
            // এই character-এর জন্য child node এখনো না থাকলে
            // নতুন node তৈরি করি
            if (curr->child[index] == nullptr)
            {
                curr->child[index] = new TrieNode();
            }
            // এখন current node-কে এই child node বানিয়ে দিই
            // অর্থাৎ পরের character নিয়ে কাজ করব
            curr = curr->child[index];
        }
        // পুরো word-এর শেষ node-এ পৌঁছে গেছি
        // তাই এখানে একটি complete word শেষ হয়েছে
        curr->isWord = true;
    }
private:
    // =========================
    // DFS SEARCH
    // =========================
    // node  = বর্তমানে Trie-এর কোন node-এ আছি
    // word  = যে word search করছি
    // index = word-এর কোন character নিয়ে কাজ করছি
    bool dfs(TrieNode *node, string &word, int index)
    {
        // যদি word-এর সব character process করা শেষ হয়
        if (index == word.size())
        {
            // এই node-এ সত্যিই কোনো complete word শেষ হয়েছে কিনা
            return node->isWord;
        }
        // বর্তমানে যে character নিয়ে কাজ করছি
        char c = word[index];
        // =========================================
        // CASE 1: Current character হলো '.'
        // =========================================
        // '.' এর অর্থ:
        // যেকোনো একটি character হতে পারে
        // যেমন:"b.t"
        // এখানে '.' = a/b/c/.../z যেকোনো একটা
        //
        if (c == '.')
        {
            // তাই 26টা possible child-এর সবগুলো check করব
            for (int i = 0; i < 26; i++)
            {
                // এই character-এর child যদি থাকে
                if (node->child[i] != nullptr)
                {
                    // এই child ধরে পরের character search করি
                    if (dfs(node->child[i], word, index + 1))
                    {
                        // কোনো একটা path যদি পুরো word match করে
                        // তাহলে সাথে সাথে true return
                        return true;
                    }
                }
            }
            // 26টা child-এর কোনো path-ই যদি
            // complete word না বানাতে পারে
            // তাহলে word পাওয়া যায়নি
            return false;
        }

        // =========================================
        // CASE 2: Current character normal character
        // =========================================
        else
        {
            // character-কে index-এ convert করি
            int idx = c - 'a';
            // এই character-এর child যদি না থাকে
            // তাহলে এই word Trie-এ নেই
            if (node->child[idx] == nullptr)
            {
                return false;
            }
            // child আছে
            // তাই সেই child node-এ গিয়ে
            // পরের character search করি
            return dfs(node->child[idx], word, index + 1);
        }
    }

public:
    // =========================
    // SEARCH WORD
    // =========================
    bool search(string word)
    {
        // root থেকে search শুরু
        // index = 0 অর্থ word-এর প্রথম character
        return dfs(root, word, 0);
    }
};
```
