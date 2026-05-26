// Problem: Trapping Rain Water
// Platform: NeetCode
// Link: https://neetcode.io/problems/trapping-rain-water/question
// time complexity: O(n); only one traverse
// space complexity: O(1); Nothing extra space


class Solution
{
public:
    int trap(vector<int> &height)
    {

        int l = 0, r = height.size() - 1;

        // বাম থেকে এখন পর্যন্ত সবচেয়ে বড় height and ডান থেকে এখন পর্যন্ত সবচেয়ে বড় height
        int leftMost = 0, rightMost = 0;
        int ans = 0;
        while (l < r)
        {
            // ছোট height এর দিক থেকে process করো
            // কারণ water সেই দিক দিয়েই সীমাবদ্ধ
            if (height[l] < height[r])
            {
                if (leftMost < height[l])
                {
                    // নতুন বড় wall পাওয়া গেছে → update করো
                    leftMost = height[l];
                }
                else
                {
                    // এই position এ water জমবে
                    // leftMost - height[l] = কতটুকু জমবে
                    ans += leftMost - height[l];
                }
                l++;
            }
            else
            {
                if (rightMost < height[r])
                {
                    // নতুন বড় wall পাওয়া গেছে → update করো
                    rightMost = height[r];
                }
                else
                {
                    // এই position এ water জমবে
                    // rightMost - height[r] = কতটুকু জমবে
                    ans += rightMost - height[r];
                }
                r--;
            }
        }
        return ans;
    }
};