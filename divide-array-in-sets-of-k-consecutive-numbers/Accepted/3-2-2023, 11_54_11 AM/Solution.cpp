// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k) return false;
        map<int,int> m;
        for(auto i: nums) m[i]++;
        for(auto [key, v]: m){
            if(m[key] == 0) continue;
            while(v--){
                for(int i = 0; i < k; i++){
                    cout << key + i << endl;
                    m[key+i]--;
                    if(m[key+i] < 0) return false;
                }
            }
        }
        return true;
    }
};