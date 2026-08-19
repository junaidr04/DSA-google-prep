// Problem: Alien Dictionary
// Platform: NeetCode
// Link: https://neetcode.io/problems/alien-dictionary
// time complexity: O(C) where C is the total number of characters in all words, as we are building a graph and performing DFS on it. Each character is processed once during the DFS traversal.
// space complexity: O(1) for the graph and state maps, as there are at most 26 unique characters (a-z) in the alien language. The space used for the answer string is also O(1) since it can contain at most 26 characters.


class Solution {
    // state[c] track kore character 'c' er DFS status:
    // 0 = unvisited, 1 = "visiting" (current DFS path e ache), 2 = "done" (completely processed)
    unordered_map<char, int> state;
    
    // final answer — DFS postorder e build hobe (pore reverse lagbe)
    string ans;
    
    // adjacency list: graph[u] = shob 'v' jekhane u->v edge ache (mane u, v er age ashe)
    unordered_map<char, unordered_set<char>> graph;
    
    bool dfs(char node) 
    {
        // jodi ei node ekhon "visiting" state e ache, mane amra abar 
        // same node e phire eshechi current DFS path e — eita CYCLE!
        if (state[node] == 1) 
            return false;
        // jodi ei node already "done" (age kono onno DFS call e process hoye geche),
        // ar notun kaj korার dorkar nai — true return kore fela
        if (state[node] == 2) 
            return true;
        // node ke "visiting" mark kori — mane ekhon current DFS path e achi
        state[node] = 1;
        // shob neighbor (jara ei node er PORE ashe alphabet e) recursively visit kori
        for (char neigh : graph[node]) 
        {
            // jodi kono neighbor e cycle paoya jay, seta upore propagate kori
            if (!dfs(neigh)) 
                return false;
        }
        // shob neighbor completely process hoye gele, ei node ke "done" mark kori
        state[node] = 2;
        // POSTORDER: node ke ans e add kori — eta shob neighbor SHESH howar POR hocche
        // (eijonyoi pore reverse lagbe, karon "pore ashe" jara age push hocche)
        ans += node;
        return true; // successfully process hoyeche, cycle nai
    }
    
public:
    string foreignDictionary(vector<string>& words) {
        
        // ============ STEP 1: shob unique character graph e add kori ============
        // eita keno lagbe: jodi kono character er kono edge na thake (karo age/pore na),
        // tabuo shei character final answer e thakte hobe — tai graph e entry chai
        for (string& s : words) 
        {
            for (char c : s) 
            {
                if (graph.find(c) == graph.end())
                    graph[c] = {}; // empty neighbor set diye initialize
            }
        }
        
        // ============ STEP 2: consecutive word pair compare kore edges ber kori ============
        for (int i = 0; i < (int)words.size() - 1; i++) 
        {
            string w1 = words[i], w2 = words[i+1];
            // duita word er modhdhe choto jaygaay porjonto compare korte parbo
            int minLen = min(w1.size(), w2.size());
            // track kori kono difference paoya geche kina
            bool found = false;
            for (int j = 0; j < minLen; j++) 
            {
                if (w1[j] != w2[j]) 
                {
                    // prothom difference paoya gelo — eita e amader edge
                    // w1[j] shobsomoy w2[j] er AGE ashe (dictionary order e)
                    graph[w1[j]].insert(w2[j]);
                    found = true;
                    break; // ar dekhar dorkar nai, prothom difference e e decide hoy
                }
            }
            
            // EDGE CASE: jodi kono difference na paoya jay (mane ekta word 
            // onnoTar prefix), ar w1 (age wala word) w2 (pore wala) theke LOMBA hoy,
            // tahole eita INVALID order (normal dictionary e choto word age ashe)
            if (!found && w1.size() > w2.size())
                return "";
        }
        
        // ============ STEP 3: shob character e DFS chalai (jodi unvisited thake) ============
        for (auto& [ch, _] : graph) 
        {
            if (state[ch] == 0) 
            {
                // jodi DFS e cycle paoya jay, mane valid order banano SOMBOB na
                if (!dfs(ch)) 
                    return "";
            }
        }
        // ============ STEP 4: postorder result ta reverse kori ============
        // DFS postorder e "pore ashe" jara, tara AGE push hoy ans e,
        // tai reverse korle thik order pai (age ashe jara, tara samne chole ashe)
        reverse(ans.begin(), ans.end());
        return ans;
    }
};