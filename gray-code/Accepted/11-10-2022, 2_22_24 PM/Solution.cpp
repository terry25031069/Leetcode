// https://leetcode.com/problems/gray-code

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<bitset<16>> tmp = {bitset<16>(0)};
        vector<int> ans;
        for(int i = 0; i < n; i++){
            auto ttmp = tmp;
            reverse(ttmp.begin(), ttmp.end());
            for(auto &b: ttmp){
                b.set(i);
            }
            tmp.insert(tmp.end(), ttmp.begin(), ttmp.end());
        }
        for(auto i: tmp){
            //cout << i.to_ulong() << ' ' << endl;
            ans.push_back(i.to_ulong());
        }
        return ans;
    }
};