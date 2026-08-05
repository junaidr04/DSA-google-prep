// Problem: Task Scheduler
// Platform: NeetCode
// Link: https://neetcode.io/problems/task-scheduler
// time complexity: O(n); প্রতিটা push/pop O(1), r amra roughly n-bar এই operation করি
// space complexity: O(1); constant extra space (at most 26 tasks in the heap)


class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        // protita character koybar ache count koro
        unordered_map<char, int> freq;
        for (char c : tasks)
        {
            freq[c]++;
        }
        // max-heap e shob frequency push koro
        // (character nijeই lagbe na, shudhu koyta baki ache eta matter kore)
        priority_queue<int> maxHeap;
        for (auto &p : freq)
        {
            maxHeap.push(p.second);
        }
        // cooldown queue: {remaining_count, available_time}
        // mane ei task abar kokhon heap e ferot ashte parbe
        queue<pair<int, int>> q;
        int time = 0;
        while (!maxHeap.empty() || !q.empty())
        {
            // Step 1: cooldown shesh hoye geche emon task heap e ferot dao
            if (!q.empty() && q.front().second == time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }
            // Step 2: ei time unit e sobcheye beshi frequency wala task process koro
            if (!maxHeap.empty())
            {
                int top = maxHeap.top();
                maxHeap.pop();
                int count = top - 1; // ekbar use hoye gelo, count komlo
                // jodi ei task er ar kaj baki thake, cooldown e pathao
                if (count > 0)
                {
                    q.push({count, time + n + 1});
                }
            }
            // heap empty hole kichu hoy na - eta implicitly IDLE time
            time++; // protibar 1 unit time pass hoy
        }
        return time;
    }
};