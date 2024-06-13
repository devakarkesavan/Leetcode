class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int sum = 0;
        int n = seats.size();
        int k = students.size();
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        for(int i=0;i<k;i++){
            if(seats[i]>students[i]){
                sum+=(seats[i]-students[i]);
            }
            else if(seats[i]<students[i]){
                sum+=(students[i]-seats[i]);
            }
        }
        return sum;
        
    }
};