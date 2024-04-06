class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0,right = 0;
        int maxf = INT_MIN;
        int maxlen = INT_MIN;
        int hash[26] = {0};
        while(right < s.length()){
            hash[s[right]-'A']++;
            maxf = max(maxf,hash[s[right]-'A']);
            if((right-left+1)-maxf>k){
                hash[s[left]-'A']--;
                left++;
            }
            maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};