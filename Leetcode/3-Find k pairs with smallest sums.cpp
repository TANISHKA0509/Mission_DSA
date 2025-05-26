#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.push({i, 0});
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto current = minHeap.top();
            minHeap.pop();
            int i = current.first;
            int j = current.second;
            result.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                minHeap.push({i, j + 1});
            }
        }

        return result;
    }
};
