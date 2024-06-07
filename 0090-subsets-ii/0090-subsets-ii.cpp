class Solution {
public:
    void fun(int ind,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        ans.push_back(ds);
        for(int i=ind;i<arr.size();i++){
            if(i!=ind && arr[i]==arr[i-1]) continue;
            ds.emplace_back(arr[i]);
            fun(i+1,arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>ds;
        fun(0,nums,ans,ds);
        return ans;
    }
};