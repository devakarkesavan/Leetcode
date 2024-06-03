class Solution {
public:
    int findVal(vector<int>&val,int mid){
        int cnt = 1;
        long long ans = 0;
        for(int i=0;i<val.size();i++){
            if(ans+val[i]<=mid){
                ans+=val[i];
            }
            else{
                cnt++;
                ans = val[i];
            }
        }
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        
        while(low<=high){
            int mid = (low+high)/2;
            int val = findVal(nums,mid);
            if(val > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};