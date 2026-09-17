class Solution {
public:

    void nextSmallerElement(vector<int>& heights, vector<int>& nextans) {
        stack<int> st;
        st.push(-1);

        int n = heights.size();

        for (int i = n - 1; i >= 0; i--) {
            int element = heights[i];

            while (st.top() != -1 && heights[st.top()] >= element) {
                st.pop();
            }

            nextans.push_back(st.top());
            st.push(i);
        }
    }

    void prevSmallerElement(vector<int>& heights, vector<int>& prevans) {
        stack<int> st;
        st.push(-1);

        int n = heights.size();

        for (int i = 0; i <= n - 1; i++) {
            int element = heights[i];

            while (st.top() != -1 && heights[st.top()] >= element) {
                st.pop();
            }

            prevans.push_back(st.top());
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {

        vector<int> nextans;
        vector<int> prevans;

        nextSmallerElement(heights, nextans);

        reverse(nextans.begin(), nextans.end());

        for (int i = 0; i < nextans.size(); i++) {
            if (nextans[i] == -1) {
                nextans[i] = heights.size();
            }
        }

        prevSmallerElement(heights, prevans);

        vector<int> area;

        for (int i = 0; i < nextans.size(); i++) {

            int width = nextans[i] - prevans[i] - 1;

            int height = heights[i];

            int currArea = width * height;

            area.push_back(currArea);
        }

        int maxArea = INT_MIN;

        for (int i = 0; i < area.size(); i++) {
            maxArea = max(maxArea, area[i]);
        }

        return maxArea;
    }
};