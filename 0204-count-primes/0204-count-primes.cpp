class Solution {
public:
    vector<int> getPrime(int n){
        vector<int>prime(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(prime[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    prime[j] = 0;
                }
            }
        }
        int cnt = 0;
        for(int i=2;i<=n;i++){
            cnt+=prime[i];
            prime[i] = cnt;
        }
        return prime;
    }
public:
    int countPrimes(int n) {
        if(n==0 || n==1 || n==2){
            return 0;
        }
        vector<int>prime = getPrime(n-1);
        return prime[n-1];
    }
};