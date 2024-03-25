class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto it:nums){
            mp[it]++;
        }
        set<int>st;
        for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
    }
    for(auto it:st){
        if(mp[it]>=2){
            ans.push_back(it);
        }
    }
    return ans;
    }
};