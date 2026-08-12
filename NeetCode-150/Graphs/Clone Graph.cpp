// Problem: Clone Graph
// Platform: NeetCode
// Link: https://neetcode.io/problems/clone-graph
// time complexity: O(V + E) where V is the number of vertices and E is the number of edges in the graph, as we need to visit each node and edge once in the worst case
// space complexity: O(V) where V is the number of vertices in the graph, as we need to store a copy of each node in the hash map

class Solution
{
    // amr নিজের "খাতা" — kon original node er clone আগে থেকেই বানানো আছে, সেটা মনে রাখার জন্য
    // key = original node, value = tar clone
    unordered_map<Node *, Node *> visited;
public:
    Node *cloneGraph(Node *node)
    {
        // 1. jodi node e kichu na thake (empty graph), thle empty node e ফেরত দাও
        if (node == nullptr)
            return node;
        // 2. ei node ta ki AMI AGE THEKEI clone koresi?
        //    jodi hae, thle NOTUN kore আবার clone banabo না
        //    khatar theke আগের banano clone ta ber kore diye দিবো
        if (visited.count(node))
            return visited[node];
        // 3. eita একদম notun node, tai clone banai
        //    (shudhu value ta copy kori, neighbors পরে বসাবো)
        Node *clone = new Node(node->val);
        // 4. khatai likhe rakhi: "eই original node -> ei clone"
        //    eita LOOP SHURU HOWAR AGE lekha jaruri (cycle handle korar জন্য, পরে বলবো কেন)
        visited[node] = clone;
        // 5. original node er প্রতিটা বন্ধু (neighbor) er জন্য:
        //    - সেই বন্ধুকেও clone koro (recursive call)
        //    - সেই cloned বন্ধুকে notun node er বন্ধু list e ঢুকাও
        for (Node *neigh : node->neighbors)
        {
            clone->neighbors.push_back(cloneGraph(neigh));
        }
        // 6. sesh e amar banano clone ta ফেরত দিয়ে দাও
        return clone;
    }
};