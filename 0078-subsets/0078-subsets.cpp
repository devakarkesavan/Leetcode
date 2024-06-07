class Solution {
public:
    void printF(vector<int>nums,vector<int>&ds,int ind,vector<vector<int>>&ans,int n){
        if(ind>=n){
            ans.push_back(ds);
            return;
        }
        int k = nums[ind];
        ds.push_back(k);
        printF(nums,ds,ind+1,ans,n);
        ds.pop_back();
        printF(nums,ds,ind+1,ans,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        // int n = nums.size();
        // for(int i=0;i<(1<<n);i++){
        //     vector<int>temp;
        //     for(int j=0;j<n;j++){
        //         if(i&(1<<j)){
        //             temp.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(temp);
        // }
        // return ans;
        int n = nums.size();
        vector<int>ds;
        printF(nums,ds,0,ans,n);
        
        return ans;
    }
};