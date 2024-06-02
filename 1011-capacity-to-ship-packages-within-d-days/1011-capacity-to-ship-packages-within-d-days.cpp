class Solution {
public:
    long long fun(int cap,vector<int>&weights){
        long long cnt = 0;
        long long days = 1;
        for(int i=0;i<weights.size();i++){
            if(cnt+weights[i]>cap){
                days+=1;
                cnt = weights[i];
            }
            else{
                cnt+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long low = *max_element(weights.begin(),weights.end());
        long long high = 0;
        for(auto it:weights){
            high+=it;
        }
        while(low<=high){
            long long mid = (low+high)/2;
            long long d = fun(mid,weights);
            if(d<=days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return (int)low;
    }
};