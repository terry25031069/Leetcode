// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(time(NULL));
        map<int, int> m;
        for(int i = 0; i < 1000; i++){
            m[nums[rand() % n]]++;
        }
        int ans = 0, cnt = 0;
        for(auto [k, v]: m){
            if(cnt < v) ans = k, cnt = v;
        }
        return ans;
    }
};