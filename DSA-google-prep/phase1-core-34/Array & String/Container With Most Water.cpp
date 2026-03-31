// Problem: Container With Most Water
// Platform: LeetCode
// Link: https://leetcode.com/problems/container-with-most-water/description/
// time complexity: O(n) using two-pointer approach
// space complexity: O(1)

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, ans = 0;
        while (l < r)
        {
            int width = r - l;
            int length = min(height[r], height[l]);
            int water = width * length;
            ans = max(ans, water);
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};