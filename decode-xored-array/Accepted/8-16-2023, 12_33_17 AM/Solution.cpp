// https://leetcode.com/problems/decode-xored-array

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans{first};
        for(auto i: encoded){
            ans.push_back(first^i), first^=i;
        }
        return ans;
    }
};