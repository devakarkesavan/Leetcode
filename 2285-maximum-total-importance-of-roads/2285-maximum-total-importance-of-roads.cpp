class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>indegree(n);
        for(auto it:roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        vector<pair<long long,long long>>in;
        for(long long i=0;i<n;i++){
            in.push_back({indegree[i],i});
        }
        sort(in.begin(),in.end(),[](pair<long long,long long> a,pair<long long,long long> b){
            return a.first > b.first;
        });
        long long temp = n;
        vector<long long>ans(n);
        for(long long i=0;i<n;i++){
            ans[in[i].second] = temp--;
        }
        long long sum = 0;
        for(auto it:roads){
            sum+=(ans[it[0]]+ans[it[1]]);
        }
        return sum;
    }
};