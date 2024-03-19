class Solution {
private:
    int f(vector<int>&arr,int d){
        int load = 0;
        int day = 1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+load > d){
                load = arr[i];
                day++;
            }
            else{
                load+=arr[i];
            }
        }
        return day;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int n = weights.size();
        int maxi = -1;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            maxi = max(maxi,weights[i]);
        }
        int low = maxi,high = sum;
        while(low<=high){
            int mid = (low+high)/2;
            int day = f(weights,mid);
            if(day <= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};