class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int left = 0,right = 0;
        int n = str.length();
        int maxi = 0;
        
        vector<int>hash(256,-1);
        
        while(right < n){
            if(hash[str[left]]!=-1 && hash[str[right]]>=left){
                left = hash[str[right]]+1;
            }
            maxi = max(right-left+1,maxi);
            hash[str[right]] = right;
            right++;
        }
        return maxi;
    }
};