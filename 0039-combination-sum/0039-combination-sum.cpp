class Solution {
public:
    void fun(int ind,vector<int>&arr,int target,vector<int>&ds,vector<vector<int>>&ans){
        if(ind==arr.size()){
            if(target==0){
                ans.emplace_back(ds);
            }
            return;
        }
        if(target>=arr[ind]){
            ds.emplace_back(arr[ind]);
            fun(ind,arr,target-arr[ind],ds,ans);
            ds.pop_back();
        }
        fun(ind+1,arr,target,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        fun(0,candidates,target,ds,ans);
        return ans;
    }
};