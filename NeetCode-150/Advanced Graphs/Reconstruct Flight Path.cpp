// Problem: Reconstruct Flight Path
// Platform: NeetCode
// Link: https://neetcode.io/problems/reconstruct-flight-path
// time complexity: O(k × E) where E is the number of edges in the graph, as we are using a BFS-like approach to explore the graph up to k stops
// space complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph


/*
Problem-টা আসলে কী বলছে?

তোমাকে কিছু flight ticket দেওয়া আছে।

প্রতিটা ticket:

[from, to]

মানে:

from airport → to airport

যেমন:

["JFK", "BUF"]

মানে:

JFK → BUF
তোমার কাজ কী?

একজন মানুষ JFK airport থেকে journey শুরু করেছে।

তার কাছে যতগুলো ticket আছে, প্রতিটা ticket ঠিক একবার করে ব্যবহার করতে হবে।

তার পুরো flight journey বের করতে হবে।

Example:

তোমার tickets:

[
    ["BUF", "HOU"],
    ["HOU", "SEA"],
    ["JFK", "BUF"]
]

এগুলোকে graph হিসেবে দেখলে:

JFK
 |
 | BUF
 ↓
BUF
 |
 | HOU
 ↓
HOU
 |
 | SEA
 ↓
SEA

অর্থাৎ journey হবে:
JFK → BUF → HOU → SEA

তাই answer:
["JFK", "BUF", "HOU", "SEA"]
*/

class Solution {
public:
    // adjacency list: from-city -> shob to-city gula (sorted order e, multiset diye)..duplicate ticket রাখতে হবে + lexicographically sorted রাখতে হবে → multiset।
    unordered_map<string, multiset<string>> graph;
    // final answer store korার jonno (reverse order e build hobe)
    vector<string> result;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Step 1: Adjacency list (graph) bana.. প্রতিটা ticket [from, to] niye graph[from] e 'to' insert kori
        for (auto& t : tickets) 
        {
            graph[t[0]].insert(t[1]); 
        }
        // Step 2: DFS shuru kori "JFK" theke (problem statement onujayi fixed start)
        dfs("JFK");
        // Step 3: DFS shesh hole result ta REVERSE order e build hoy 
        // (keno sheta niche explain korবো), tai reverse kore thik order e ante hobe
        reverse(result.begin(), result.end());
        return result;
    }
    void dfs(string node) 
    {
        // jotokkhon 'node' theke r kono unused ticket ache (graph[node] khali na)
        while (!graph[node].empty()) 
        {
            // multiset er PROTHOM element ber kori — eita SHOBCHEYE CHOTO 
            // (alphabetically) destination, karon multiset sorted thake
            string next = *graph[node].begin(); 
            // ei ticket ta "use kore fellam" — tai graph theke REMOVE kori
            // (jate abar dobara ei EKই ticket use na hoy)
            graph[node].erase(graph[node].begin());
            
            // ekhon 'next' city te giye abar DFS kori (recursive call)
            dfs(next);
        }
        
        // *** KEY PART: while loop shesh hoye গেলে (mane 'node' theke r 
        // kono ticket baki nai, DEAD END) ***
        // tokhon 'node' ke result e push kori
        result.push_back(node);
    }
};