// https://leetcode.com/problems/find-the-peaks

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        if(mountain.size() < 3) return {};
        vector<int> ans;
        for(int i = 0; i < mountain.size() - 2; i++){
            if(mountain[i+1] > mountain[i] && mountain[i+1] > mountain[i+2])
                ans.push_back(i + 1);
        }
        return ans;
    }
};