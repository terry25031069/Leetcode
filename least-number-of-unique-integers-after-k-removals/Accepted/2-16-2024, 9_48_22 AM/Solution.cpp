// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> m;
        for(int ele: arr) m[ele]++;
        vector<int> v;
        for(auto [k, val]: m){
            v.push_back(val);
        }
        sort(v.begin(), v.end());
        int coord = 0;
        while(coord < v.size() && k >= v[coord]) k -= v[coord], coord += 1;
        return v.size() - coord;
    }
};