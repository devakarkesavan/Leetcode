class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int sum = 0;
        int n = seats.size();
        int k = students.size();
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(int i=0;i<k;i++){
            sum+=abs(seats[i]-students[i]);
        }
        return sum;
        
    }
};