// Problem: Search in Rotated Sorted Array
// Platform: LeetCode
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// time complexity: O(log n) using binary search
// space complexity: O(1)

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid])
            {
                if (target < nums[mid] && target >= nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};