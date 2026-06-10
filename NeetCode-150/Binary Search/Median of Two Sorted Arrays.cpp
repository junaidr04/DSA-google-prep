// Problem: Median of Two Sorted Arrays
// Platform: NeetCode
// Link: https://neetcode.io/problems/median-of-two-sorted-arrays
// time complexity: O(log(min(m, n))) where m and n are the lengths of the two arrays
// space complexity: O(1); only a few variables are used


class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // সবসময় ছোট array তে binary search করো
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = nums1.size();
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            // mid1 = nums1 থেকে কতটা left half এ নেবো
            int mid1 = mid;

            // mid2 = nums2 থেকে কতটা left half এ নেবো
            int mid2 = (nums1.size() + nums2.size() + 1) / 2 - mid1;

            // nums1 এর left half এর সবচেয়ে বড় element
            int maxLeft1;
            if (mid1 == 0)
                maxLeft1 = INT_MIN; // nums1 থেকে কিছু নেইনি
            else
                maxLeft1 = nums1[mid1 - 1];

            // nums1 এর right half এর সবচেয়ে ছোট element
            int minRight1;
            if (mid1 == nums1.size())
                minRight1 = INT_MAX; // nums1 সব নিয়েছি
            else
                minRight1 = nums1[mid1];

            // nums2 এর left half এর সবচেয়ে বড় element
            int maxLeft2;
            if (mid2 == 0)
                maxLeft2 = INT_MIN; // nums2 থেকে কিছু নেইনি
            else
                maxLeft2 = nums2[mid2 - 1];

            // nums2 এর right half এর সবচেয়ে ছোট element
            int minRight2;
            if (mid2 == nums2.size())
                minRight2 = INT_MAX; // nums2 সব নিয়েছি
            else
                minRight2 = nums2[mid2];

            // valid partition — left এর সব ≤ right এর সব
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
            {
                int totalLen = nums1.size() + nums2.size();

                // odd → left half এর maximum
                if (totalLen % 2 == 1)
                    return max(maxLeft1, maxLeft2);

                // even → left max + right min / 2
                else
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
            // nums1 এর partition বেশি ডানে → বামে সরাও
            else if (maxLeft1 > minRight2)
                r = mid - 1;

            // nums1 এর partition বেশি বামে → ডানে সরাও
            else
                l = mid + 1;
        }
    }
};