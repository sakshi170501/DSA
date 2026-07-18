class Solution {
public:
    string reorganizeString(string s) {

        int map[256] = {0};

        // Count frequency
        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;
        }

        // Find maximum frequency character
        char max_freq_char = 'a';
        int max_freq = INT_MIN;

        for (int i = 'a'; i <= 'z'; i++) {
            if (map[i] > max_freq) {
                max_freq = map[i];
                max_freq_char = i;
            }
        }

        // Impossible case
        if (max_freq > (s.size() + 1) / 2) {
            return "";
        }

        int index = 0;

        // Place most frequent character
        while (max_freq > 0 && index < s.size()) {
            s[index] = max_freq_char;
            max_freq--;
            index += 2;
        }

        map[max_freq_char] = 0;

        // Place remaining characters
        for (int i = 'a'; i <= 'z'; i++) {
            while (map[i] > 0) {

                if (index >= s.size())
                    index = 1;

                s[index] = i;
                map[i]--;
                index += 2;
            }
        }

        return s;
    }
};