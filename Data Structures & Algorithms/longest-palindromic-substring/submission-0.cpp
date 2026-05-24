class Solution {
public:
    string longestPalindrome(string s) {
        int bestStart = 0;
        int bestLen = 1;

        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i, bestStart, bestLen);       
            expand(s, i, i + 1, bestStart, bestLen);
        }

        return s.substr(bestStart, bestLen);
    }

    void expand(string& s, int left, int right, int& bestStart, int& bestLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        int length = right - left - 1;
        int start = left + 1;

        if (length > bestLen) {
            bestLen = length;
            bestStart = start;
        }
    }
};