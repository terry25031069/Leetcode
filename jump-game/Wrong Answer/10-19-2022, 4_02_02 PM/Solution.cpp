// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        int sta = 0, loc = 0;    
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << ' ' << sta  << endl;
            if(sta < nums[i]){
                loc = i;
                sta = 0;
            }else{
                sta++;
            }
        }
        cout << loc << endl;
        return (loc == nums.size() - 1);
    }
};