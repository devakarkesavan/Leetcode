class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int ones = 0,twos=0;
        // for(int i=0;i<nums.size();i++){
        //     ones = (ones^nums[i])&(~twos);
        //     twos = (twos^nums[i])&(~ones);
        // }
        // return ones;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=3){
            if(nums[i]!=nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
};