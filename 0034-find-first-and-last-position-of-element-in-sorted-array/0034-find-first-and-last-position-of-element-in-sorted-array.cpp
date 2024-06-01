class Solution {
public:
    int upperBound(vector<int>&nums,int target){
        int n = nums.size();
        int low = 0,high = n-1;
        int ans= -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<target){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
public:
    int lowerBound(vector<int>&nums,int target){
        int n = nums.size();
        int low = 0,high = n-1;
        int ans= -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                ans = mid;
                high= mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(find(nums.begin(), nums.end(), target)==nums.end()) return {-1, -1};
        int k = lower_bound(nums.begin(), nums.end(),target) - nums.begin();
        int p = upper_bound(nums.begin(), nums.end(),target) - nums.begin();
        return {k, p-1};
    }
};