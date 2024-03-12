// https://leetcode.com/problems/random-pick-with-weight

class Solution {
public:
    vector<int> weight;
    Solution(vector<int>& w) {
        weight = w;
        for(int i = 1; i < weight.size(); i++) weight[i] += weight[i-1];
    }
    
    int pickIndex() {
        int r = rand() % weight.back();
        return lower_bound(weight.begin(), weight.end(), r) - weight.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */