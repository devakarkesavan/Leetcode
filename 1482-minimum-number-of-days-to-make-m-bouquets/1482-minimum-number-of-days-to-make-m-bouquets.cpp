class Solution {
public:
    bool fun(long long mid,vector<int>&v,int m,int k){
        long long tot = 0,cnt = 0;
        for(int i=0;i<v.size();i++){
            if(v[i]<=mid){
                cnt++;
            }
            else{
                tot+=(cnt/k);
                cnt = 0;
            }
        }
        tot+=(cnt/k);
        if(tot>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)n<(long long)m*k){
            return -1;
        }
        long long  low = *min_element(bloomDay.begin(),bloomDay.end());
        long long  high= *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid = (low+high)/2;
            bool pos = fun(mid,bloomDay,m,k);
            if(pos==true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return (int)low;
    }
};