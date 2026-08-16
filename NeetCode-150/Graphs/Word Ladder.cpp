// Problem: Word Ladder
// Platform: NeetCode
// Link: https://neetcode.io/problems/word-ladder
// time complexity: O(M² × N) where M is the length of each word and N is the total number of words in the word list
// space complexity: O(M × N) for the adjacency list and visited set

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        // wordList ke unordered_set e convert korlam -- fast O(1) lookup
        // korার jonno, karon BFS er modhye bar bar check korte hobe
        // "ei word ta valid neighbor kina" -- vector hole eta slow (O(n)) hoto
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // jodi endWord wordSet e na thake, tahole kono valid path hওয়া
        // possible na (কারণ শেষ পর্যন্ত পৌঁছানোর জন্য endWord list e thakteই হবে)
        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        // BFS queue -- protitа element e (current word, ekhon porjonto koyটা
        // step lagলো / level) pair rakhchi
        queue<pair<string, int>> q;
        // beginWord queue e push kori, level = 1 diয়ে shuru (karon beginWord
        // nijeo count হয় sequence er length e)
        q.push({beginWord, 1});
        // beginWord ke wordSet theke erase kore dilam -- eta "visited mark
        // kora" er kaj korche, jate eta abার kono neighbor hisebe dhora na pore
        wordSet.erase(beginWord);
        // BFS loop shuru
        while (!q.empty())
        {
            // queue er shamner element ber kore anlam (word ar tar level)
            auto [word, level] = q.front();
            q.pop();
            // jodi ei word-i endWord hoy, tahole eta-i shortest path,
            // karon BFS level-by-level explore kore, tai প্রথমবার
            // endWord pele-i guaranteed shortest
            if (word == endWord)
                return level;
            // current word er shob possible "1-letter-different" neighbor khuje ber kora
            for (int i = 0; i < word.size(); i++)
            {
                // position i er original letter save kore rakhlam,
                // pore restore korার jonno
                char original = word[i];
                // ei position e a theke z porjonto protitа letter try kore dekhi
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c; // notun letter বসিয়ে দিলাম
                    // jodi ei notun word wordSet e paওয়া যায় (mane valid ebong
                    // ekhono visited hoyni), tahole eta ekটা valid neighbor
                    if (wordSet.find(word) != wordSet.end())
                    {
                        wordSet.erase(word);       // visited mark kore dilam
                        q.push({word, level + 1}); // queue e push, level+1 soho
                    }
                }
                // shob letter try kore dekhার por, position i ke abার
                // original letter e ferot niye elam -- nahole notun word
                // permanently corrupt hoye jaবে, r porer position e vul word
                // theke check hবে
                word[i] = original;
            }
        }
        // queue khali hওয়ার পরেও endWord na paওয়া গেলে, mane kono path nai
        return 0;
    }
};