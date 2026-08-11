// Problem: Word Search II
// Platform: NeetCode
// Link: https://neetcode.io/problems/word-search-ii
// time complexity: O(M * N * 4^L); M = rows, N = columns, L = length of the longest word
// space complexity: O(K * L); K = number of words, L = average length of words

/*
Shob word alada-alada kore check korle (protiটA word-er jonno alada DFS), same prefix (jemon "cat", "car", "cap" — shobar "ca" porjonto same) baar baar explore hobe grid-e — slow.Trie use korle shob word-er common prefix ekbar-i store hoy. Grid-e DFS korার shomoy Trie follow kore, ekবার "c"→"a" path check korলেই shob word (ja "ca" diye shuru) ekসাথে check hoye jay. R jodi kono prefix Trie-te na thake, shathe shathe oi branch prune kore fela jay (r egiye lav nai) — eta boro grid + boro word list-e onek time bachay.  
*/

class TrieNode
{
public:
    TrieNode *child[26]; // 26-ta English letter-er jonno child pointer array
    string isWord = "";  // khali string mane ei node e kono word shesh hoy na, non-empty hole eta pura word ta store kore rakhe
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr; // shuru te shob child null
        }
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        // ------- Step 1: shob word diye ekta Trie build kora -------
        TrieNode *root = new TrieNode();
        for (string s : words)
        {
            TrieNode *curr = root;
            for (char c : s)
            {
                int index = c - 'a';
                if (curr->child[index] == nullptr)
                {
                    curr->child[index] = new TrieNode(); // path na thakle notun node banao
                }
                curr = curr->child[index]; // Trie te ekta level niche namo
            }
            curr->isWord = s; // word-er shesh node e pura word ta store kore rakho
        }

        // ------- Step 2: grid-er protiটA cell theke DFS shuru kora -------
        vector<string> result; // matched word gula ekhane joma hobe
        int rows = board.size(), cols = board[0].size();
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                dfs(row, col, board, root, result); // protiটA starting point theke DFS
            }
        }
        return result;
    }

    void dfs(int row, int col, vector<vector<char>> &board, TrieNode *node, vector<string> &result)
    {
        int r = board.size(), c = board[0].size();
        // ------- Base case 1: grid-er baire chole gele stop -------
        if (row < 0 || row >= r || col < 0 || col >= c)
        {
            return;
        }
        // ------- Base case 2: cell already visited (eiই path e) hole stop -------
        if (board[row][col] == '#')
        {
            return;
        }
        char ch = board[row][col];
        int idx = ch - 'a';
        // ------- Pruning: ei character diye Trie te kono path na thakle
        //         emni-i egiye lav nai, ekhane-i thamiye dao -------
        if (node->child[idx] == nullptr)
            return;
        node = node->child[idx]; // Trie te ekta level niche namo (current path follow kore)
        // ------- Match paoya gele: result e add koro, r duplicate atkate
        //         shei node-er word clear kore dao -------
        if (node->isWord != "")
        {
            result.push_back(node->isWord);
            node->isWord = ""; // ekই word abar match korle jeno duibar add na hoy
        }
        // ------- Current cell visited mark koro (temporarily) -------
        board[row][col] = '#';
        // ------- 4 direction e recursively explore koro (up, down, left, right) -------
        dfs(row + 1, col, board, node, result);
        dfs(row - 1, col, board, node, result);
        dfs(row, col + 1, board, node, result);
        dfs(row, col - 1, board, node, result);
        // ------- Backtrack: cell ke abar original character e ফিরিয়ে dao,
        //         jate onno path e eta abar visit kora jay -------
        board[row][col] = ch;
    }
};