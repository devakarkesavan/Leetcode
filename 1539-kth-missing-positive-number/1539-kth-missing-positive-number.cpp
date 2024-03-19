class Solution {
public:
    int findKthPositive(vector<int>& vec, int k) {
        int n = vec.size();
        int low = 0,high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        int mis = vec[mid]-(mid+1);
        if(mis<k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    // return k+high+1;
     return low+k;
    }
};