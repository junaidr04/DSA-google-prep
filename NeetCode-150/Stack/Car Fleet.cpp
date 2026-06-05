// Problem: Car Fleet
// Platform: NeetCode
// Link: https://neetcode.io/problems/car-fleet
// time complexity: O(n log n); sorting the cars by their starting positions takes O(n log n) time, and traversing the sorted list of cars takes O(n) time.
// space complexity: O(n); in the worst case, when all cars form a single fleet, the stack will hold all n cars.


class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        // position আর speed একসাথে pair করো
        vector<pair<int, int>> car;
        for (int i = 0; i < position.size(); i++)
        {
            car.push_back({position[i], speed[i]});
        }
        // position descending order এ sort করো
        // সামনের car (target এর কাছের) আগে process হবে
        sort(car.rbegin(), car.rend());

        // প্রতিটা fleet এর time store করবে
        // stack এর size = fleet count
        stack<float> st;

        //car vector-এর প্রতিটি pair থেকে first কে pos এবং second কে spd নামে নিয়ে loop চালাও।
        for (auto [pos, spd] : car)
        {
            // এই car টার target পৌঁছাতে কত সময় লাগবে
            float time = (float)(target - pos) / spd;

            // stack empty অথবা এই car এর time সামনের car এর চেয়ে বেশি?
            // বেশি মানে সামনের car কে ধরতে পারবে না → নতুন fleet
            // কম বা সমান মানে সামনের car কে ধরে ফেলবে → same fleet, skip
            if (st.empty() || st.top() < time)
            {
                st.push(time);
            }
            else
            {
                continue;
            }
        }
        // stack এ যতগুলো fleet আছে সেটাই answer
        return st.size();
    }
};
