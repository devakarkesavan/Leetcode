class Solution {
char s1, s2;
private:
    bool pal(int i, int j, string &s){
        if(i>j){
            return true;
        }
        if(!isalnum(s[i])) return pal(i+1, j, s);
        if(!isalnum(s[j])) return pal(i, j-1, s);
        s1 = tolower(s[i]);
        s2 = tolower(s[j]);
        if(s1==s2)
            return pal(i+1, j-1, s);
        else
            return false;
        
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        return pal(0, n-1, s);
    }
};