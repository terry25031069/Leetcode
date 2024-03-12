// https://leetcode.com/problems/most-frequent-even-element

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int>cnt;
        for(int i: nums) if(i % 2 == 0)cnt[i]++;
        int ma = -1, man;
        if(!cnt.size()) return -1;
        for(auto i: cnt){
            cout << i.first << ' ' << i.second << endl;
            if(i.second > ma){
                ma = i.second;
                man = i.first;
            }
        }
        return man;
    }
};