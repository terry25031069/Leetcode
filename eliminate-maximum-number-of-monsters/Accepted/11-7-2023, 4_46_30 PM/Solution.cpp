// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

#define F first
#define S second

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        for(int i = 0; i < dist.size(); i++){
            time.push_back((double)dist[i] / speed[i]);
        }
        sort(time.begin(), time.end());
        int cnt = 0;
        for(int i = 0; i < time.size(); i++){
            if(time[i] > i) cnt++;
            else break;
        }
        return cnt;
    }
};
