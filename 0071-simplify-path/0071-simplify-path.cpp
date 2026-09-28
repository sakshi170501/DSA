class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp = "";
        string ans = "";

        for (int i = 0; i <= path.length(); i++) {
            if (i == path.length() || path[i] == '/') {

                if (temp == "..") {
                    if (!st.empty()) {
                        st.pop();
                    }
                }
                else if (temp != "" && temp != ".") {
                    st.push(temp);
                }

                temp = "";
            }
            else {
                temp += path[i];
            }
        }

        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if (ans == "") {
            return "/";
        }

        return ans;
    }
};