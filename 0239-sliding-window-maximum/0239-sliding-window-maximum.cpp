class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int index = 0; index < k; index++) {
            while (!dq.empty() && nums[dq.back()] < nums[index]) {
                dq.pop_back();
            }
            dq.push_back(index);
        }
        int element = nums[dq.front()];
        ans.push_back(element);
        for (int index = k; index < nums.size(); index++) {
            if (!dq.empty() && dq.front() <= index - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[index]) {
                dq.pop_back();
            }
            dq.push_back(index);
            int element = nums[dq.front()];
            ans.push_back(element);
        }
        return ans;
    }
};