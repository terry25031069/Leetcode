// https://leetcode.com/problems/reward-top-k-students

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        map<string, int> m;
        for(auto i: positive_feedback) m[i] = 3;
        for(auto i: negative_feedback) m[i] = -1;
        vector<vector<int>> scores; vector<int> ans;
        for(int i = 0; i < report.size(); i++){
            stringstream ss; ss.str(report[i]);
            string s;
            int score = 0;
            while(ss >> s) score += m[s];
            scores.push_back({100000 - score, student_id[i]});
        }
        sort(scores.begin(), scores.end());
        for(int i = 0; k--; i++){
            ans.push_back(scores[i][1]);
        }
        return ans;
    }
};