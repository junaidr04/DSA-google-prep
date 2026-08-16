// Problem: Redundant Connection
// Platform: NeetCode
// Link: https://neetcode.io/problems/redundant-connection
// time complexity: O(N · α(N)) where N is the number of nodes and α(N) is the inverse Ackermann function (very slow-growing, practically constant)
// space complexity: O(N) for the parent and rank arrays

class Solution
{
    // parent[x] = x এর direct parent (leader এর দিকে)
    // shuru te protitа node nijer nijei parent
    vector<int> parent;
    // Rank[x] = x er tree er approximate height/size
    // union by rank optimization er jonno use kori
    vector<int> Rank;
    // ------ find(x): x er root/leader ta khuje ber kore ------
    int find(int x)
    {
        // jodi x nijei nijer parent hoy, mane x-i root/leader
        if(parent[x] == x)
            return x;
        // Path compression: root khuje pele, path er shob node er
        // parent directly root e set kore dei -- ete future find()
        // call gulo onek fast hoy (near O(1) amortized)
        return parent[x] = find(parent[x]);
    }
    // ------ unite(x, y): x r y ke ekই group e merge kore ------
    // return kore false jodi x, y already same group e thake (mane cycle!)
    // return kore true jodi merge successful hoy
    bool unite(int x, int y)
    {
        int rootX = find(x), rootY = find(y);
        // dujoner root already same -- mane already connected,
        // ei edge ta add korle notun kono connection hobe na,
        // borong cycle toiri korবে -- eটাই redundant connection
        if(rootX == rootY)
            return false;
        // Union by rank: choto rank er tree ke boro rank er
        // tree এর নিচে বসাই, যাতে tree খুব বেশি লম্বা না হয়ে যায়
        if(Rank[rootX] < Rank[rootY])
            parent[rootX] = rootY;       // X choto, Y এর নিচে বসলো
        else if(Rank[rootX] > Rank[rootY])
            parent[rootY] = rootX;       // Y choto, X এর নিচে বসলো
        else
        {
            // rank same hole, jekono ekটাকে leader banaই,
            // r shei leader er rank ekটা barhiye dei
            parent[rootY] = rootX;
            Rank[rootX]++;
        }
        return true;   // merge successful, cycle na
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        // ei problem e n টা node hole n টা edge thake (tree hote
        // n-1 lagto, extra 1 টা edge-i redundant connection)
        // tai n = edges.size() dhorle-i chole
        int n = edges.size();
        // parent r Rank array size n+1 rakhchi, karon ei problem e
        // node numbering shadharonoto 1 theke shuru hoy (0 na),
        // tai index 0 unused rekhe safe thakchi
        parent.resize(n + 1);
        Rank.assign(n + 1, 0);
        // shuru te protitа node nijer nijei parent (shobai আলাদা group)
        for(int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        // ------ edges gulo ekta ekta kore process kori (input order অনুযায়ী) ------
        for(auto& e : edges)
        {
            int a = e[0], b = e[1];

            // unite() false dile mane a, b already same group e chilo,
            // ei edge ta cycle toiri korche -- eটাই answer, shathe shathe return
            if(!unite(a, b))
                return e;
        }
        // ei point e kokhono pouchanor kotha na (problem guarantee kore
        // ekটা redundant edge thakবেই), tobuo safe default হিসেবে empty
        return {};
    }
};