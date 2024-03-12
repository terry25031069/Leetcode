// https://leetcode.com/problems/sort-the-people

class Solution {
public:
    vector<int> h;
    static bool cmp(pair<string, int> a, pair<string, int> b){
        return a.second > b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string, int>> data;
        for(int i = 0; i < names.size(); i++){
            data.push_back({names[i], heights[i]});
        }
        sort(data.begin(), data.end(), cmp);
        names.clear();
        for(auto i: data){
            names.push_back(i.first);
        }
        return names;
    }
};