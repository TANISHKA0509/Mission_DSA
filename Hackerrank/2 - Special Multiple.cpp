string solve(int N) {
     if (N == 0) return "0"; 
    queue<string> q;
    unordered_set<int> visited;
    q.push("9");
    visited.insert(9 % N);
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        long long num = stoll(current);
        if (num % N == 0) {
            return current;
        }
        string next = current + "0";
        long long nextNum = stoll(next);
        int mod = nextNum % N;
        if (visited.find(mod) == visited.end()) {
            visited.insert(mod);
            q.push(next);
        }
        next = current + "9";
        nextNum = stoll(next);
        mod = nextNum % N;
        if (visited.find(mod) == visited.end()) {
            visited.insert(mod);
            q.push(next);
        }
    }
    return "";

}
