class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int count = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                count++;
                depth = max(depth, count);
            }
            if (ch == ')') {
                count--;
            }
        }
        return depth;
    }
};