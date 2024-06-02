class Solution {
public:
    long long fun(long long mid,vector<int>& piles){
        long long total =0;
        for(int i=0;i<piles.size();i++){
            total+=ceil((double)piles[i] / (double)mid);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1,high= *max_element(piles.begin(),piles.end());
        while(low<=high){
            long long mid = (low+high)/2;
            long long totHours = fun(mid,piles);
            if(totHours<=h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return (int)low;
    }
};