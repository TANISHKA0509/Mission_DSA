class Solution {
public:
    int shortestSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        std::deque<int> dq;
        int min_len = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                min_len = std::min(min_len, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        return min_len == INT_MAX ? -1 : min_len;
    }
};
