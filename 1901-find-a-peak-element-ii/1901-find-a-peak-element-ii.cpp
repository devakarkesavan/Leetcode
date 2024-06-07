class Solution {
public:
    int maxElement(vector<vector<int>>&arr,int n,int m,int mid){
        int maxi = -1;
        int ind = -1;
        for(int i=0;i<n;i++){
            if(arr[i][mid]>maxi){
                maxi = arr[i][mid];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int low = 0,high = m-1;
        while(low<=high){
            int mid = (low+high)/2;
            int maxRow = maxElement(arr,n,m,mid);
            int left = mid-1>=0? arr[maxRow][mid-1]:-1;
            int right = mid+1<m? arr[maxRow][mid+1]:-1;
            if(arr[maxRow][mid]>left && arr[maxRow][mid]>right){
                return {maxRow,mid};
            }
            else if(arr[maxRow][mid] < left){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};