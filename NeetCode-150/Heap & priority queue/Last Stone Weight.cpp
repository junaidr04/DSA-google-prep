/*
=====================================================
LAST STONE WEIGHT - PROBLEM UNDERSTANDING
=====================================================

Ekta array of stones deya ache, protita number ekta
stone er weight represent kore.

GAME RULES:
- Protibar amra shob theke BHARI 2-ta stone uthabo
  (dhori weight y ar x, jekhane y >= x)
- Ora ekshathe smash hoy:
    -> jodi x == y hoy, dutai COMPLETELY DESTROY hoye jay
       (kono stone bache na)
    -> jodi x != y hoy, x stone destroy hoy, r y stone er
       notun weight hoy (y - x) -- eta ekta NOTUN stone
       hisebe theke jay
- Ei process repeat hobe jotokkhon na 1-ta ba 0-ta stone bache

GOAL:
- Last e ja stone bache tar weight return korte hobe
- Jodi kono stone na bache (shob mile completely destroy),
  tahole 0 return korte hobe

EXAMPLE:
stones = [2, 7, 4, 1, 8, 1]

Step 1: sobcheye bhari 2-ta -> 8, 7
        smash -> 8-7 = 1 bache
        stones remaining: [2, 4, 1, 1, 1]

Step 2: sobcheye bhari 2-ta -> 4, 2
        smash -> 4-2 = 2 bache
        stones remaining: [2, 1, 1, 1]

Step 3: sobcheye bhari 2-ta -> 2, 1
        smash -> 2-1 = 1 bache
        stones remaining: [1, 1, 1]

Step 4: sobcheye bhari 2-ta -> 1, 1
        smash -> equal! dutai gayeb hoye gelo
        stones remaining: [1]

ANSWER = 1 (last bacha stone)


WHY HEAP?
---------
Protibar amader "sob theke bhari 2-ta stone" lagbe.
Normal array hole protibar sort korte hobe (O(n log n)
protibar), jeta slow.

MAX-HEAP use korle, sobcheye bhari stone (top) always
O(1) e pawa jay, r remove/insert hoy O(log n) e.
Tai heap ei problem er jonno perfect fit.


APPROACH (Plan):
-----------------
1. Shob stone ekta max-heap e push kore dao
2. Jotokkhon heap e >= 2 ta stone ache, loop chalao:
     - top theke 2-ta stone pop koro (y = boro ta, x = 2nd boro)
     - difference (y - x) calculate koro
     - jodi difference 0 na hoy, seta abar heap e push koro
       (eta notun stone hisebe consider hobe porer round e)
     - jodi 0 hoy, kichu push korar dorkar nai (dutai gayeb)
3. Loop shesh hole heap e 0 ba 1-ta stone bachbe:
     - empty hole return 0
     - na hole heap er top i answer
*/

// Problem: Last Stone Weight
// Platform: NeetCode
// Link: https://neetcode.io/problems/last-stone-weight
// time complexity: O(n log n); প্রতিটা push/pop O(log n), r amra roughly n-bar এই operation করি
// space complexity: O(n); max-heap e shob stone store korte hobe

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxHeap; // default max-heap - top e always sobcheye bhari stone thakbe

        // shob stone heap e push kore dilam ekbar
        for (int c : stones)
        {
            maxHeap.push(c);
        }

        // jotokkhon kompokkhe 2-ta stone ache, smash korte thakbo
        while (maxHeap.size() >= 2)
        {
            int y = maxHeap.top(); // sobcheye bhari
            maxHeap.pop();
            int x = maxHeap.top(); // 2nd sobcheye bhari
            maxHeap.pop();

            // jodi equal na hoy, difference ta notun stone hisebe abar heap e felo
            // equal hole kichu push korar dorkar nai - dutai gayeb hoye gelo
            if (y - x != 0)
            {
                maxHeap.push(y - x);
            }
        }

        // loop shesh - ekhon heap e 0 ba 1-ta stone bache
        if (maxHeap.empty())
            return 0;         // shob stone destroy hoye geche
        return maxHeap.top(); // last bacha stone
    }
};