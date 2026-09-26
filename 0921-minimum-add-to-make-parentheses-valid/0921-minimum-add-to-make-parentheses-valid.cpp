class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
                count++;
            }
            else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    count--;
                }
                else {
                    count++;
                }
            }
        }

        return count;
    }
};