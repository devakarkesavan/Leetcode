class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int>num;
        int fact = 1;
        for(int i=1;i<n;i++){
            fact = fact*i;
            num.emplace_back(i);
        }
        num.emplace_back(n);
        k = k-1;
        while(true){
            ans = ans + to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0){
                return ans;
            }
            k = k%fact;
            fact = fact/num.size();
        }
        return ans;
    }
};