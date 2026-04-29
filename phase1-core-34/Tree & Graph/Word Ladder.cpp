// Problem: Word Ladder
// Platform: LeetCode
// Link: https://leetcode.com/problems/word-ladder/description/
// time complexity: O(N × M) where N is the number of words in the word list and M is the length of each word, as we need to generate all possible transformations for each word and check if they are in the word set
// space complexity: O(N × L) where N is the number of words in the word list and L is the length of each word, as we need to store the visited words in a queue for BFS and a set for visited words... or O(N) if we only consider the space used for the visited set, as the queue will at most contain N words in the worst case

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty())
        {
            auto [word, level] = q.front();
            q.pop();
            if (word == endWord)
            {
                return level;
            }
            for (int i = 0; i < word.size(); i++)
            {
                string newWord = word;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    newWord[i] = c;
                    if (wordSet.count(newWord) && !visited.count(newWord))
                    {
                        q.push({newWord, level + 1});
                        visited.insert(newWord);
                    }
                }
            }
        }
        return 0;
    }
};