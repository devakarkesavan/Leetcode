class Solution {
public:
    int fun(vector<int>&nums,int k){
        if(k<0){
            return 0;
        }
        int sum = 0;
        int cnt = 0;
        int right = 0,left=0;
        
        while(right < nums.size()){
            sum+=nums[right];
            while(sum>k){
                sum-=nums[left];
                left++;
            }
            cnt+=right-left+1;
            right++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }
        return fun(nums,k)-fun(nums,k-1);
    }
};