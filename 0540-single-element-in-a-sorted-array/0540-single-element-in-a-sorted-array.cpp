class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;

        while (s <= e) {
            if (s == e) {
                return arr[s];
            }

            int mid = s + (e - s) / 2;

            int currentValue = arr[mid];

            int leftValue = -1;
            if (mid - 1 >= 0)
                leftValue = arr[mid - 1];

            int rightValue = -1;
            if (mid + 1 < n)
                rightValue = arr[mid + 1];

            // Single element found
            if (currentValue != leftValue && currentValue != rightValue) {
                return currentValue;
            }

            // Pair starts at mid-1
            if (currentValue == leftValue && currentValue != rightValue) {
                int pairStartingIndex = mid - 1;

                if (pairStartingIndex & 1) {
                    e = pairStartingIndex - 1;
                } else {
                    s = pairStartingIndex + 2;
                }
            }

            // Pair starts at mid
            else if (currentValue != leftValue && currentValue == rightValue) {
                int pairStartingIndex = mid;

                if (pairStartingIndex & 1) {
                    e = pairStartingIndex - 1;
                } else {
                    s = pairStartingIndex + 2;
                }
            }
        }

        return -1;
    }
};