class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        if(n==0){
            return false;
        }
        int m = matrix[0].length;
        int low = 0,high= n*m-1;
        int mid_ind,row_ind,col_ind;
        while(low<=high){
            mid_ind = (low+high)/2;
            row_ind = mid_ind/m;
            col_ind = mid_ind%m;
            int mid_element = matrix[row_ind][col_ind];
            if(mid_element == target){
                return true;
            }
            else if(mid_element < target){
                low = mid_ind+1;
            }
            else{
                high = mid_ind-1;
            }
        }
        return false;
    }
}