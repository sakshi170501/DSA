class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry > 0) {

            int sum = 0;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            sum += carry;

            int lastBit = sum % 2;
            ans.push_back(lastBit + '0');

            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};