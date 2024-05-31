class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0,right = 0;
        int n = s.length();
        int maxf = 0;
        int maxlen = 0;
        vector<int>arr(26,0);
        while(right < n){
            arr[s[right]-'A']++;
            maxf = max(maxf,arr[s[right]-'A']);
            if((right-left+1)-maxf > k){
                arr[s[left]-'A']--;
                maxf = 0;
                left++;
            }
            if((right-left+1)-maxf <= k){
                maxlen = max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};