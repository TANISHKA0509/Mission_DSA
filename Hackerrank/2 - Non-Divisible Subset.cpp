int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> remainder_counts(k, 0);
    for (int num : s) {
        remainder_counts[num % k]++;
    }
    
    int max_size = 0;
    if (remainder_counts[0] > 0) {
        max_size = 1;
    }
    
    for (int i = 1; i <= k / 2; ++i) {
        if (i != k - i) {
            max_size += max(remainder_counts[i], remainder_counts[k - i]);
        } else {
            max_size += 1;
        }
    }
    
    return max_size;

}
