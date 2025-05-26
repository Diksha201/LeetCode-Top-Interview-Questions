class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.length() < totalLen) return res;

        unordered_map<string, int> wordMap;
        for (string& word : words) wordMap[word]++;

        // Shift i in range of wordLen to avoid missing any window
        for (int i = 0; i < wordLen; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> windowMap;

            for (int j = i; j <= int(s.length()) - wordLen; j += wordLen) {
                string word = s.substr(j, wordLen);
                if (wordMap.count(word)) {
                    windowMap[word]++;
                    count++;

                    // Shrink window until word count matches original
                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Check if all words matched
                    if (count == wordCount) {
                        res.push_back(left);
                    }
                } else {
                    windowMap.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return res;
    }
};