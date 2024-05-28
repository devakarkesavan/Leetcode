class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int m = n;
        n = abs(n);
        while(n>0){
            if(n%2==1){
                n-=1;
                ans*=x;
            }
            else{
                n/=2;
                x*=x;
            }
        }
        if(m<0){
            return (1.0/ans);
        }
        return ans;
    }
};