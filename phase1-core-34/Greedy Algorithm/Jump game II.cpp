// Problem: Jump Game II
// Platform: LeetCode
// Link: https://leetcode.com/problems/jump-game-ii/
// time complexity: O(n) - where n is the length of the array. We iterate through the array once.
// space complexity: O(1) - we only use a constant amount of extra space.


class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int jump = 0, currEnd = 0, farthest = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);
            if (i == currEnd)
            {
                jump++;
                currEnd = farthest;
            }
        }
        return jump;
    }
};