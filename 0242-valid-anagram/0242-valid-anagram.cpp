class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        for(auto it:t){
            mpp[it]--;
            if(mpp[it]==0){
                mpp.erase(it);
            }
        }
        return mpp.size()==0;
    }
};