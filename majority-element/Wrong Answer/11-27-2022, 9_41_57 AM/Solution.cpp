// https://leetcode.com/problems/majority-element

class Solution {
public:
    int arrcnt(vector<int>tmp){
        map<int, int>cnt;
        int ans = -1, ansc = -1;
        for(auto i: tmp){
            cnt[i]++;
            if(ansc < cnt[i]) ans = i, ansc = cnt[i];
        }
        //cout << ans << ' ' << ansc << endl;
        return ans;
    }
    int majorityElement(vector<int>& nums) {
        vector<int> tmp;
        int ans;
        if(nums.size() < 30) return arrcnt(nums);
        cout << "yee\n";
        for(int i = 0; i < 10; i++){
            tmp.push_back(nums[rand() % nums.size()]);
        }
        return arrcnt(tmp);
    }
};