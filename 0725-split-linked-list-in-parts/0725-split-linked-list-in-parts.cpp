class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int N = 0;
        auto it = head;

        // Find length
        while(it) {
            N++;
            it = it->next;
        }

        int idealpartsize = N / k;
        int extranodes = N % k;

        vector<ListNode*> ans(k, nullptr);

        it = head;

        for(int i = 0; i < k && it; i++) {

            // Starting node of current part
            ans[i] = it;

            // First 'extranodes' parts get one extra node
            int actualpartsize =
                idealpartsize + (extranodes-- > 0 ? 1 : 0);

            // Move to the last node of current part
            for(int j = 0; j < actualpartsize - 1; j++) {
                it = it->next;
            }

            // Save starting node of next part
            auto nextpartstarting = it->next;

            // Break current part
            it->next = nullptr;

            // Move to next part
            it = nextpartstarting;
        }

        return ans;
    }
};