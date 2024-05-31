class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>arr(256,0);
        int m = t.length();
        for(auto it:t){
            arr[it]++;
        }
        
        int left = 0,right = 0;
        int n = s.length();
        int startIndex = -1,maxLen = INT_MAX;
        int cnt = 0;
        while(right < n){
            if(arr[s[right]]>0){
                cnt+=1;
            }
            arr[s[right]]--;
            while(cnt==m){
               if(right-left+1 < maxLen){
                   maxLen = right-left+1;
                   startIndex  = left;
               }
                arr[s[left]]++;
                if(arr[s[left]]>0){
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return startIndex==-1?"":s.substr(startIndex,maxLen);
    }
};