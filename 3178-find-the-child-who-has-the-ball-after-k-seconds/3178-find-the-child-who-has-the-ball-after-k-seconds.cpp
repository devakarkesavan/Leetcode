class Solution {
public:
    int numberOfChild(int n, int k) {
        int val = 1,place = 0;
        for(int i=0;i<k;i++){
            if(place==0){
                val = 1;
            }
            else if(place==n-1){
                val=-1;
            }
            place+=val;
        }
        return place;
        
    }
};