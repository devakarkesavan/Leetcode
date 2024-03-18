class Solution {
private:
    long long f(vector<int>& v,long long h){
        long long sum = 0;
        for(int i=0;i<v.size();i++){
            sum += ceil((double)v[i]/(double)h);
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long  high =*max_element(piles.begin(),piles.end());
        while(low<=high){
            long long mid = (low+high)/2;
            long long hours = f(piles,mid);
            if(hours<=h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return (int)low;
    }
};