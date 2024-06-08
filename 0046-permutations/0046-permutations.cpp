class Solution {
public:
    void fun(vector<vector<int>>&ans,int ind,vector<int>&nums){
        if(ind==nums.size()){
            ans.emplace_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            fun(ans,ind+1,nums);
            swap(nums[ind],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        fun(ans,0,nums);
        return ans;
    }
};