// https://leetcode.com/problems/maximize-greatness-of-an-array

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        map<int, int> m;
        for(auto i: nums) m[i]++;
        int ans = 0;
        vector<int> match, matched;
        int p1 = 0, p2 = 1;
        for(auto [k, v]: m) matched.push_back(v);
        match = matched;
        int m1 = 0, m2 = 1;
        while(m2 < m.size()){
            int tmp = min(matched[m2], match[m1]);
            ans += tmp;
            match[m1] -= tmp;
            while(match[m1] == 0) m1++;
            m2++;
        }
        return ans;
    }
};