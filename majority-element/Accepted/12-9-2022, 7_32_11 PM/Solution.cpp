// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ma = -1, cnt = 0;
        for(int i: nums){
            if(ma == i){
                cnt++;
            }else{
                if(cnt > 0)cnt--;
                else ma = i, cnt = 1;
            }
        }
        return ma;
    }
};