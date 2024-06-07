class Solution {
public:
    void fun(vector<vector<int>>&ans,vector<int>&ds,vector<int>&nums,vector<int>&freq){
        if(ds.size()==nums.size()){
            ans.emplace_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i] = 1;
                ds.emplace_back(nums[i]);
                fun(ans,ds,nums,freq);
                ds.pop_back();
                freq[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n = nums.size();
        vector<int>freq(n,0);
        fun(ans,ds,nums,freq);
        return ans;
    }
};