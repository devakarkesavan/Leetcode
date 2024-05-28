class Solution {
public:
    int minBitFlips(int start, int goal) {
        int val = start ^ goal;
        int cnt = 0;
        while(val){
            cnt++;
            val = val&(val-1);
        }
        return cnt;
    }
};