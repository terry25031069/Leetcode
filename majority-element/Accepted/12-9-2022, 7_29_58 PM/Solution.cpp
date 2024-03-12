// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int>cnt; int ma = -1, man = 0;
        for(int i: nums){
            cnt[i]++;
            if(cnt[i] > ma){
                ma = cnt[i], man = i;
            }
        }
        return man;
    }
};