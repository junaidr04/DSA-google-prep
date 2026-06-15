// Problem: Find the Duplicate Number
// Platform: NeetCode
// Link: https://neetcode.io/problems/find-the-duplicate-number
// time complexity: O(n); where n is the number of elements in the array
// space complexity: O(1); we are using only a constant amount of space to store the pointers


class Solution
{
    class Solution
    {
    public:
        int findDuplicate(vector<int> &nums)
        {
            int slow = 0, fast = 0;

            // Loop 1 — cycle detect করো
            // slow একে একে এগায়, fast দুই দুই করে
            // duplicate থাকলে cycle হবে → slow == fast হবে
            do
            {
                slow = nums[slow];       // 1 step
                fast = nums[nums[fast]]; // 2 steps
            } while (slow != fast); // meet না হওয়া পর্যন্ত চলো

            // Loop 2 — cycle এর entry point খোঁজো
            // entry point = duplicate number
            // slow2 = 0 থেকে শুরু, slow = meet point থেকে শুরু
            // দুইজন same speed এ এগালে entry point এ মিলবে
            int slow2 = 0;
            while (slow != slow2)
            {
                slow = nums[slow];   // meet point থেকে এগাও
                slow2 = nums[slow2]; // শুরু থেকে এগাও
            }

            // slow == slow2 == duplicate number
            return slow;
        }
    };