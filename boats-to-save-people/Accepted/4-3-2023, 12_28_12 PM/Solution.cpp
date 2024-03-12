// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1, ans = 0;
        while(l <= r){
            //cout << l << ' ' << r << ' ' << ans << endl;
            if(people[l] + people[r] > limit) r--, ans++;
            else l++, r--, ans++;
        }
        return ans;
    }
};