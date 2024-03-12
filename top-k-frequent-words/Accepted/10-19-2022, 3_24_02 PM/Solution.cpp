// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    static bool sortfunc(pair<string, int>a, pair<string, int>b){
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    }
    map<string, int>find;
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(int i = 0; i < words.size(); i++){
            find[words[i]]++;
        }
        vector<pair<string, int>> tmp;
        vector<string>ans;
        for(auto i: find){
            tmp.push_back({i.first, i.second});
        }
        sort(tmp.begin(), tmp.end(), sortfunc);
        for(int i = 0; i < k; i++){
            ans.push_back(tmp[i].first);
        }
        return ans;
    }
};