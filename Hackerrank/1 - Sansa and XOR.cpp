int sansaXor(vector<int> arr) {
     int n = arr.size();
    int result = 0;
    for (int i = 0; i < n; ++i) {
        long long count = (i + 1LL) * (n - i);
        if (count % 2 == 1) {
            result ^= arr[i];
        }
    }
    return result;

}
