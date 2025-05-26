#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countSubarraysDivByK(const vector<int>& nums, int k) {
    unordered_map<int, int> mod_map;
    mod_map[0] = 1; 
    int prefix_mod = 0;
    long long count = 0;
    
    for (int num : nums) {
        prefix_mod = (prefix_mod + num % k + k) % k; 
        count += mod_map[prefix_mod];
        mod_map[prefix_mod]++;
    }
    
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        cout << countSubarraysDivByK(nums, k) << "\n";
    }
    
    return 0;
}
