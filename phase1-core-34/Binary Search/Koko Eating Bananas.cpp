// Problem: Koko Eating Bananas
// Platform: LeetCode
// Link: https://leetcode.com/problems/koko-eating-bananas/description/
// time complexity: O(nlogm)
// space complexity: O(1)

class Solution
{
public:
    int canFinish(vector<int> &piles, int k, int h)
    {
        int hour = 0;
        for (int p : piles)
        {
            hour += (p + k - 1) / k;
        }
        return hour <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (canFinish(piles, mid, h))
            {
                right = mid;
            }
            else
            { 
                left = mid + 1;
            }
        }
        return left;
    }
};
