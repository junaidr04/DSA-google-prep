// Problem: Encode and Decode Strings
// Platform: Neetcode
// Link: https://neetcode.io/problems/string-encode-and-decode/question
// time complexity: O(n)
// space complexity: O(n)


class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string ans = "";
        for (string s : strs)
        {
            // প্রতিটা word এর আগে তার length আর # রাখো
            // "neet" → "4#neet"
            // to_string() — int কে string এ convert করে
            ans += to_string(s.size()) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s)
    {
        vector<string> ans;
        // i = current position, encoded string এর উপর দিয়ে হাঁটবে
        int i = 0;
        while (i < s.size())
        {
            // i position থেকে # খোঁজো
            // j = # এর index
            int j = s.find('#', i);
            // i থেকে j এর মধ্যের number → word এর length
            // "4#neet" এ i=0, j=1, len=1 → "4"
            int len = j - i;
            // len কে int এ convert করো
            // substr(i, len) → i থেকে len টা character নাও
            int wordLen = stoi(s.substr(i, len));
            // j+1 থেকে wordLen টা character নাও → actual word
            // "4#neet" এ j+1=2, wordLen=4 → "neet"
            string word = s.substr(j + 1, wordLen);
            ans.push_back(word);
            // i কে পরের word এর শুরুতে নিয়ে যাও
            // j+1 = # এর পরে, wordLen = word টা পার হয়ে
            i = j + 1 + wordLen;
        }
        return ans;
    }
};