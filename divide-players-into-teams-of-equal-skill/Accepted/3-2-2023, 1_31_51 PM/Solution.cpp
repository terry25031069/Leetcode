// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int tot = skill[0] + skill.back();
        long long ans = 0;
        for(int i = 0, j = skill.size() - 1; i < j; i++, j--){
            if(skill[i] + skill[j] - tot) return -1;
            ans += int64_t(skill[i]) * skill[j];
        }
        return ans;
    }
};