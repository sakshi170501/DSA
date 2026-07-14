class Solution {
public:
    bool isvalid(char ch) {
        if ((ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z')) {
            return true;
        }
        return false;
    }

    // Returns the cleaned string
    string validPalindrome(string s) {
        string newStr = "";

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isvalid(ch)) {
                if (ch >= 'A' && ch <= 'Z') {
                    ch = ch - 'A' + 'a';
                }
                newStr.push_back(ch);
            }
        }

        return newStr;
    }

    bool isPalindrome(string s) {
        string newStr = validPalindrome(s);

        int i = 0;
        int j = newStr.length() - 1;

        while (i < j) {
            if (newStr[i] != newStr[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};