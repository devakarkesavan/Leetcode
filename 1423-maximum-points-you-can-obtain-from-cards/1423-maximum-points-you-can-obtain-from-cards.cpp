class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0,rightSum=0;
        int n = cardPoints.size();
        
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
        }
        int maxi = leftSum;
        
        int rightIndex = n-1;
        for(int i=k-1;i>=0;i--){
            leftSum = leftSum-cardPoints[i];
            rightSum += cardPoints[rightIndex];
            rightIndex--;
            maxi = max(leftSum+rightSum,maxi);
        }
        
        return maxi;
    }
};