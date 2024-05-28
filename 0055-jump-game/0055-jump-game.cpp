class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInterval = 0;
        for(int i=0;i<nums.size();i++){
            if(i>maxInterval){
                return false;
            }
            maxInterval = max(maxInterval,i+nums[i]);
        }
        return true;
    }
};