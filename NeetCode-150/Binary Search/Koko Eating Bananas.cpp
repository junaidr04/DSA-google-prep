// Problem: Koko Eating Bananas
// Platform: NeetCode
// Link: https://neetcode.io/practice/koko-eating-bananas
// time complexity: O(log(max_pile - min_pile) * n); binary search on the eating speed, where n is the number of piles.. O(nlogn) in the worst case when max_pile is much larger than min_pile
// space complexity: O(1); only a few variables are used


class Solution
{
public:
    // helper function — k speed এ h hours এ শেষ করা যাবে?
    int canFinish(vector<int> &piles, int k, int h)
    {
        int hour = 0;
        for (int p : piles)
        {
            // প্রতিটা pile শেষ করতে কত hour লাগবে
            // ceil(p/k) = (p+k-1)/k — integer ceiling division
            // যেমন: pile=7, k=4 → ceil(7/4) = 2 hours
            hour += (p + k - 1) / k;
        }

        // মোট hour h এর মধ্যে হলে এই speed এ সম্ভব
        return hour <= h;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {

        // minimum speed = 1 (সবচেয়ে ধীরে)
        // maximum speed = সবচেয়ে বড় pile (এক ঘণ্টায় যেকোনো pile শেষ)
        int l = 1, r = *max_element(piles.begin(), piles.end());

        // boundary search — l < r
        // loop শেষে l == minimum valid speed
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            // এই speed এ শেষ করা যাবে?
            // যাবে → আরো কম speed এ try করো → r কমাও
            // যাবে না → speed বাড়াতে হবে → l বাড়াও
            if (canFinish(piles, mid, h))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        // l == minimum speed যেটায় h hours এ শেষ করা যাবে
        return l;
    }
};