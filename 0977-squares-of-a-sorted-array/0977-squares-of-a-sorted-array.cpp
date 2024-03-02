class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        for(auto it:nums){
            int k = pow(it,2);
            ans.push_back(k);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};