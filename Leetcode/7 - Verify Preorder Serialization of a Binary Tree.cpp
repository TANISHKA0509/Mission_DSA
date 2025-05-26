
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes;
        stringstream ss(preorder);
        string token;
        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }
        
        int slots = 1;
        for (const string& node : nodes) {
            if (slots == 0) return false; // No slot available
            slots--; // Consume one slot
            if (node != "#") slots += 2; // Non-empty node creates two slots
        }
        
        return slots == 0;
    }
};
