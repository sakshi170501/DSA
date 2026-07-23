class Solution {
public:
    int start = 0;
    int maxLen = 0;

    void expand(string &s, int i, int j) {
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            if (j - i + 1 > maxLen) {
                maxLen = j - i + 1;
                start = i;
            }
            i--;
            j++;
        }
    }

    string longestPalindrome(string s) {

        for (int center = 0; center < s.length(); center++) {

            // Odd length palindrome
            expand(s, center, center);

            // Even length palindrome
            expand(s, center, center + 1);
        }

        return s.substr(start, maxLen);
    }
};