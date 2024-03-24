class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:nums){
            if(mp[it]>=2){
                return it;
            }
        }
        return -1;
    }
};