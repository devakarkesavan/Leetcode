class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(),happiness.end());
        int l = n-1;
        long long sumOfHappiness = happiness[l];
        l--;
        k--;
        int t = 1;
        while(k--){
            int sum = happiness[l];
            int c = sum-t;
            if(c>0){
                sumOfHappiness+=c;
            }
            l--;
            t++;
        }
        return sumOfHappiness;
    }
};