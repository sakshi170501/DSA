class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = binaryfirstsearch(nums, target);
        ans[1] = binarylastsearch(nums, target);
        return ans;
    }

    int binaryfirstsearch(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                ans = mid;
                e = mid - 1;
            }
            else if (nums[mid] > target) {
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }

    int binarylastsearch(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                ans = mid;
                s = mid + 1;
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }
};