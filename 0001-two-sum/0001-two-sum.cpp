class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int a = nums[i];
            int m = target-a;
            if(mp.find(m)!=mp.end()){
                return {mp[m],i};
            }
            mp[a] = i;
        }
      return {};     
    }
};