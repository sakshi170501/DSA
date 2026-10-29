
class Solution {
public:
    class Info {
    public:
        int data;
        int rindex;
        int cindex;

        Info(int a, int b, int c) {
            data = a;
            rindex = b;
            cindex = c;
        }
    };

    class compare {
    public:
        bool operator()(Info* a, Info* b) {
            return a->data > b->data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        int totalrows = nums.size();

        for (int row = 0; row < totalrows; row++) {
            int element = nums[row][0];

            Info* temp = new Info(element, row, 0);
            pq.push(temp);

            maxi = max(maxi, element);
            mini = min(mini, element);
        }

        int ans_start = mini;
        int ans_end = maxi;

        while (!pq.empty()) {
            Info* front = pq.top();
            pq.pop();

            int frontData = front->data;
            int front_rindex = front->rindex;
            int front_cindex = front->cindex;

            mini = frontData;

            if ((maxi - mini) < (ans_end - ans_start)) {
                ans_start = mini;
                ans_end = maxi;
            }

            if (front_cindex + 1 < nums[front_rindex].size()) {
                int element = nums[front_rindex][front_cindex + 1];

                Info* temp = new Info(
                    element, front_rindex, front_cindex + 1
                );

                maxi = max(maxi, element);
                pq.push(temp);
            } else {
                break;
            }

        
        }

        return {ans_start, ans_end};
    }
};
