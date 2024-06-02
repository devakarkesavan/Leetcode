class Solution {
public:
    int fun(long long mid,vector<int>&nums,int threshold){
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += ceil((double)nums[i]/(double)mid);
        }
        return ans<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long low = 1,high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            long long mid = (low+high)/2;
            bool ans = fun(mid,nums,threshold);
            if(ans){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return (int)low;
    }
};