// https://leetcode.com/problems/minimum-time-difference

class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int>tmp;
        for(auto i: time){
            string x = i.substr(0, 2);
            string y = i.substr(3, 2);
            tmp.push_back(stoi(x) * 60 + stoi(y));
        }
        int diff = 1e9;
        sort(tmp.begin(), tmp.end());
        for(int i = 0; i < tmp.size(); i++){
            int idiff = abs(tmp[(i + 1) % tmp.size()] - tmp[i]);
            diff = min(diff, min(idiff, 1440 - idiff));
        }
        return diff;
    }
};