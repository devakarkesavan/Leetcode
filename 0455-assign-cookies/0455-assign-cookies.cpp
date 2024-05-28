class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n =g.size(),m = s.size();
        int l = 0, r= 0;
        while(l<m && r<n){
            if(g[r] <= s[l]){
                r++;
            }
            l+=1;
        }
        return r;
    }
};