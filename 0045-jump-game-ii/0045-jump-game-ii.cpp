class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0,left=0,right=0;
        int n = nums.size();
        while(right<n-1){
            int farthest = 0;
            for(int i=left;i<=right;i++){
                farthest = max(farthest,i+nums[i]);
            }
            left = right+1;
            right = farthest;
            jumps=jumps+1;
        }
        return jumps;
    }
};