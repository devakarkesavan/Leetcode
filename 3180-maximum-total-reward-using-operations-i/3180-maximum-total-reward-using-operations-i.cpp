class Solution {
public:
    int maxTotalReward(vector<int>& arr) {
        int maxi = 0;
        int n= arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>memo(n+1);
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            memo[i].push_back(arr[i]);
            mpp[arr[i]]++;
            maxi = max(maxi,arr[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                for(auto it:memo[j]){
                    if(arr[i]>it && mpp[arr[i] + it]==0){
                        memo[i].push_back(arr[i]+it);
                        mpp[arr[i]+it]++;
                        maxi = max(maxi,arr[i]+it);
                    }
                }
            }
        }
        return maxi;
    }
};