// https://leetcode.com/problems/count-nice-pairs-in-an-array

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long long ans = 0;
        map<vector<int>, int> m;
        for(auto n: nums){
            string tmps = to_string(n);
            vector<int> tmpv;
            for(int i = 0; i < tmps.size() - 1; i++){
                tmpv.push_back(tmps[i + 1] - tmps[i]);
            }
            int chk = 1;
            for(auto e: tmpv){
                if(e){
                    chk = 0; break;
                }
            }
            if(chk == 1){
                m[{0}]++;
            }else{
                m[tmpv]++;
            }
        }
        for(auto [k, v]: m){
            ans += v * (v - 1) / 2;
        }
        ans %= int(1e9 + 7);
        return ans;
    }
};