// https://leetcode.com/problems/data-stream-as-disjoint-intervals

class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
        s.clear();
        s.insert(1e5);
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int l = *s.begin(), r = *s.begin();
        for(auto i: s){
            if(i == r + 1) r++;
            else if(i > r + 1){
                ans.push_back({l, r});
                l = r = i;
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */