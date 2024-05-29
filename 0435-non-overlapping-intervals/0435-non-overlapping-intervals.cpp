class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>>arr;
        int n = intervals.size();
        for(auto it:intervals){
            int st = it[0];
            int en = it[1];
            arr.push_back({en,st});
        }
        sort(arr.begin(),arr.end());
        int cnt = 1;
        int freetime = arr[0].first;
        for(int i = 1; i < n; i++){
            if(arr[i].second >= freetime){
                cnt++;
                freetime = arr[i].first;
            }
        }
        return n-cnt;
    }
};