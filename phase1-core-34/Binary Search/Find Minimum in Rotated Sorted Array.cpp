// Problem: Find Minimum in Rotated Sorted Array
// Platform: LeetCode
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// time complexity: O(log n) using binary search
// space complexity: O(1)

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return nums[l];
    }
};