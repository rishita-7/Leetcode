class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int left=0;
        int right=people.size()-1;
        int boats=0;
        while(left<=right){
            if(people[left]+people[right]<= (long)limit){
                boats++;
                left++;
                right--;
            }
            else if(people[left]+people[right]>(long)limit){
                boats++;
                right--;
            }
        }
        return boats;
    }
};