// https://leetcode.com/problems/successful-pairs-of-spells-and-potions

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int N = spells.size(), M = potions.size();
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for(int e: spells){
            int tmp = M;
            int l = 0, r = M - 1, m;
            while(l <= r){
                m = l + (r - l) / 2;
                if(potions[m] * e >= success){
                    tmp = m;
                    r = m - 1;
                }else{
                    l = m + 1;
                }   
            }
            ans.push_back(M - tmp);
        }
        return ans;
    }
};