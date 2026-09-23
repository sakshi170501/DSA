class Solution {
public:

    // Next Smaller or Equal
    vector<int> nextSmallerElement(vector<int>& v) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size(), -1);

        for (int i = v.size() - 1; i >= 0; i--) {

            while (!st.empty() &&
                   st.top() != -1 &&
                   v[st.top()] >= v[i]) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    // Previous Smaller
    vector<int> prevSmallerElement(vector<int>& v) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size(), -1);

        for (int i = 0; i < v.size(); i++) {

            while (!st.empty() &&
                   st.top() != -1 &&
                   v[st.top()] > v[i]) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    // Next Greater or Equal
    vector<int> nextGreaterElement(vector<int>& v) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size(), -1);

        for (int i = v.size() - 1; i >= 0; i--) {

            while (!st.empty() &&
                   st.top() != -1 &&
                   v[st.top()] <= v[i]) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    // Previous Greater
    vector<int> prevGreaterElement(vector<int>& v) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size(), -1);

        for (int i = 0; i < v.size(); i++) {

            while (!st.empty() &&
                   st.top() != -1 &&
                   v[st.top()] < v[i]) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {

        auto next = nextSmallerElement(arr);
        auto prev = prevSmallerElement(arr);

        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {

            long long nexti =
                (next[i] == -1) ? arr.size() : next[i];

            long long previ = prev[i];

            long long left = i - previ;
            long long right = nexti - i;

            long long nooftimes = left * right;

            long long total = nooftimes * arr[i];

            sum += total;
        }

        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {

        auto next = nextGreaterElement(arr);
        auto prev = prevGreaterElement(arr);

        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {

            long long nexti =
                (next[i] == -1) ? arr.size() : next[i];

            long long previ = prev[i];

            long long left = i - previ;
            long long right = nexti - i;

            long long nooftimes = left * right;

            long long total = nooftimes * arr[i];

            sum += total;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {

        long long smallestSums = sumSubarrayMins(nums);

        long long largestSums = sumSubarrayMaxs(nums);

        return largestSums - smallestSums;
    }
};