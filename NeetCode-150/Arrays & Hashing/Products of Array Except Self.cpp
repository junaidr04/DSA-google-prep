// Problem: Products of Array Except Self
// Platform: Neetcode
// Link: https://neetcode.io/problems/products-of-array-discluding-self/question
// time complexity: O(n)
// space complexity: O(n)


// Approach 1
// TC: O(n)
// SC: O(n)
//
// Idea:
// 1. left[i]  = i এর বাম পাশের সব number এর product
// 2. right[i] = i এর ডান পাশের সব number এর product
// 3. answer[i] = left[i] * right[i]
//
// Example:
// nums = [1,2,4,6]
//
// left  = [1,1,2,8]
// right = [48,24,6,1]
//
// ans = [48,24,12,8]


class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        // left[i] -> left side product store করবে
        vector<int> left(n, 1);
        // right[i] -> right side product store করবে
        vector<int> right(n, 1);
        vector<int> ans(n);
        // ---------------- LEFT PRODUCT ----------------
        // left[i] = left[i-1] * nums[i-1]
        // Example:
        // nums = [1,2,4,6]
        // left[0] = 1
        // left[1] = 1
        // left[2] = 1*2 = 2
        // left[3] = 1*2*4 = 8
        // left = [1,1,2,8]
        for (int i = 1; i < n; i++)
        {
            left[i] = nums[i - 1] * left[i - 1];
        }
        // ---------------- RIGHT PRODUCT ----------------
        // right[i] = right[i+1] * nums[i+1]
        // Example:
        // right[3] = 1
        // right[2] = 6
        // right[1] = 6*4 = 24
        // right[0] = 24*2 = 48
        // right = [48,24,6,1]
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = nums[i + 1] * right[i + 1];
        }
        // ans[i] = left[i] * right[i]
        //
        // Example:
        // ans[0] = 1 * 48 = 48
        // ans[1] = 1 * 24 = 24
        // ans[2] = 2 * 6  = 12
        // ans[3] = 8 * 1  = 8
        for (int i = 0; i < n; i++)
        {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};


// TC: O(n)
// SC: O(1)

// Approach 2 (Optimized)
// TC: O(n)
// SC: O(1)   // answer array বাদ দিলে extra space নাই
//
// Trick:
// আলাদা left/right array লাগবে না
//
// Step 1:
// ans এর ভিতরে prefix product রাখবো
//
// Step 2:
// right side product একটা variable r দিয়ে handle করবো


class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        // STEP 1: PREFIX PRODUCT STORE
        //
        // ans[i] = i এর বাম পাশের সব number এর product
        //
        // nums = [1,2,4,6]
        //
        // ans[0] = 1
        // ans[1] = 1
        // ans[2] = 1*2 = 2
        // ans[3] = 1*2*4 = 8
        //
        // ans = [1,1,2,8]
        ans[0] = 1;
        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        // STEP 2: RIGHT PRODUCT
        //
        // r = right side product
        //
        // শুরুতে:
        // r = 1
        //
        // এখন ডান দিক থেকে আসবো
        // আর ans[i] *= r করবো
        int r = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            // left product * right product
            ans[i] *= r;
            // right product update
            r *= nums[i];
        }
        // Example walkthrough:
        //
        // nums = [1,2,4,6]
        //
        // initial ans = [1,1,2,8]
        //
        // i=3:
        // ans[3] = 8*1 = 8
        // r = 1*6 = 6
        //
        // i=2:
        // ans[2] = 2*6 = 12
        // r = 6*4 = 24
        //
        // i=1:
        // ans[1] = 1*24 = 24
        // r = 24*2 = 48
        //
        // i=0:
        // ans[0] = 1*48 = 48
        return ans;
    }
};