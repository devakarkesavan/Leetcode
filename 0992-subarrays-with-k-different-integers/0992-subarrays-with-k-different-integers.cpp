class Solution {
public:
    int fun(vector<int>&nums,int k){
        int right =0,left=0;
        int cnt = 0;
        unordered_map<int,int>mpp;
        
        while(right < nums.size()){
            mpp[nums[right]]++;
            while(mpp.size()>k){
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};