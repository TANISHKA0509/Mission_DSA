 const int MOD = 1e9 +7 ;
int substrings(string n) {
   
    long long total = 0;
    long long current_sum = 0;
    int length = n.size();
    
    for (int i = 0; i < length; ++i) {
        current_sum = (current_sum * 10 + (n[i] - '0') * (i + 1)) % MOD;
        total = (total + current_sum) % MOD;
    }
    
    return total;
}
