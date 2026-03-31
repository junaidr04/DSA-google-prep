// Problem: Trapping Rain Water
// Platform: LeetCode
// Link: https://leetcode.com/problems/trapping-rain-water/description/
// time complexity: O(n) using two-pointer approach
// space complexity: O(1)

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1, leftMost = 0, rightMost = 0, ans = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (leftMost < height[left])
                {
                    leftMost = height[left];
                }
                else
                {
                    ans += leftMost - height[left];
                }
                left++;
            }
            else
            {
                if (rightMost < height[right])
                {
                    rightMost = height[right];
                }
                else
                {
                    ans += rightMost - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};