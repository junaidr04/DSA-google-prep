/*
=====================================================
K CLOSEST POINTS TO ORIGIN - PROBLEM UNDERSTANDING
=====================================================

Ekta list of points deya ache 2D plane e, protita point
[x, y] format e.

GOAL:
- Origin (0, 0) theke sobcheye KACHE (closest) k-ta
  point ber korte hobe
- Return order kono matter kore na

DISTANCE FORMULA:
- Euclidean distance = sqrt(x^2 + y^2)
- KINTU sqrt() calculate korar dorkar nai!
  Karon amra shudhu COMPARE korchi kon distance boro/choto.
  sqrt function monotonic (order change hoy na), tai
  x^2 + y^2 compare korleo shothik result pawa jay.
  Eta calculation fast rakhe (sqrt costly operation).

EXAMPLE:
points = [[1,3],[-2,2]], k = 1

distance of [1,3]  = 1^2 + 3^2 = 1 + 9  = 10
distance of [-2,2] = (-2)^2 + 2^2 = 4 + 4 = 8

[-2,2] er distance choto (8 < 10), tai eta closer
ANSWER = [[-2,2]]


WHY MAX-HEAP? (size-k restricted approach)
--------------------------------------------
Amader "closest k" (mane smallest distance) chai.

Jodi amra heap e SHUDHU size k rakhi, ar heap er modhe
je sobcheye DURE (mane boro distance) take felay dei
protibar size k er beshi hoile, tahole shesh porjonto
heap e thakbe closest k-ta point.

Eijonno amader dorkar MAX-HEAP - jar top e always
sobcheye BORO distance (mane sobcheye DURE thaka point)
thakbe, jate seta easily felay dewa jay.

Eta ager "Kth Largest Element in a Stream" er MIRROR:
- Oikhane "top k largest" chilo -> MIN-heap use kore
  chota gulo felechilam
- Ekhane "top k closest (smallest distance)" chai ->
  MAX-heap use kore dure(boro) gulo felbo


APPROACH (Plan):
-----------------
1. Max-heap banao: pair<int distance, vector<int> point>
   (default priority_queue pair er FIRST element (distance)
    diye compare kore, tai custom comparator lagena)

2. Protita point er jonno:
     - distance = x*x + y*y (sqrt lagbe na)
     - heap e push koro {distance, point}
     - jodi heap size k theke boro hoye jay,
       TOP pop koro (mane sobcheye dure thaka point felo)

3. Loop shesh hole heap e thakbe EXACTLY closest k-ta point

4. Heap theke shob point ber kore ans vector e push koro
   (order matter kore na)

5. ans return koro

*/
// Problem: K Closest Points to Origin
// Platform: NeetCode
// Link: https://neetcode.io/problems/k-closest-points-to-origin
// time complexity: O(n log k); প্রতিটা push/pop O(log k), r amra roughly n-bar এই operation করি
// space complexity: O(k); max-heap e shob point store korte hobe

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        // max-heap: pair<distance, point>
        // default priority_queue pair er FIRST element (distance) diye compare kore
        // tai automatically max-heap of distances hoye jay - custom comparator lagena
        priority_queue<pair<int, vector<int>>> maxHeap;
        for (vector<int> &c : points)
        {
            // sqrt lagena - x^2 + y^2 compare korleo same order pawa jay
            int dist = c[0] * c[0] + c[1] * c[1];
            maxHeap.push({dist, c});
            // heap size k theke boro hoye gele, sobcheye DURE thaka point felay dao
            // (max-heap er top mane sobcheye boro distance, mane sobcheye dure)
            if (maxHeap.size() > k)
            {
                maxHeap.pop();
            }
        }
        // ei point e heap e ache exactly closest k-ta point
        // shob ber kore ans e felo (order kono matter kore na)
        while (!maxHeap.empty())
        {
            ans.push_back(maxHeap.top().second); // .second = point
            maxHeap.pop();
        }
        return ans;
    }
};