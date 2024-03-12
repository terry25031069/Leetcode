// https://leetcode.com/problems/minimum-genetic-mutation

class Solution {
public:
    struct node{
        string s;
        int step;
    };
    int minMutation(string start, string end, vector<string>& bank) {
        set<string>chk; 
        for(auto i: bank) chk.emplace(i);
        if(!chk.count(end)) return -1;

        queue<node>q;
        q.push({start, 0});
        while(!q.empty()){
            node top = q.front(); q.pop();
            string word = "ACTG";
            for(int i = 0; i < top.s.size(); i++){
                for(int j = 0; j < 4; j++){
                    if(top.s[i] != word[j]){
                        string tmp = top.s;
                        tmp[i] = word[j];
                        if(chk.count(tmp)){
                            if(tmp == end) return top.step + 1;
                            q.push({tmp, top.step + 1});
                        }
                    }
                }
            }
        }  
        return -1;
    }
};