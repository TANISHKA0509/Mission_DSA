class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        int max_freq = 0;
        for (auto& entry : freq) {
            max_freq = std::max(max_freq, entry.second);
        }

        int num_max_tasks = 0;
        for (auto& entry : freq) {
            if (entry.second == max_freq) {
                num_max_tasks++;
            }
        }

        int min_intervals = (max_freq - 1) * (n + 1) + num_max_tasks;
        return std::max(min_intervals, static_cast<int>(tasks.size()));
    }
};
