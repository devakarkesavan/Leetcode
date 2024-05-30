class Solution {
public:
    bool checkValidString(string s) {
        int mini =0, maxi = 0;
        for(auto it:s){
            if(it=='('){
                maxi+=1;
                mini+=1;
            }
            else if(it==')'){
                mini-=1;
                maxi-=1;
            }
            else{
                mini-=1;
                maxi+=1;
            }
            if(mini<0){
                mini = 0;
            }
            if(maxi<0){
                return false;
            }
        }
        return mini==0;
    }
};