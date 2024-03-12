// https://leetcode.com/problems/best-team-with-no-conflicts

class Solution {
public:
    struct p{
        int score, age;
        p(int score, int age): score(score), age(age){};
    };
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<p> people;
        for(int i = 0; i < scores.size(); i++){
            people.push_back(p(scores[i], ages[i]));
        }
        sort(people.begin(), people.end(), [](p a, p b){
            if(a.age != b.age) return a.age < b.age;
            return a.score < b.score;
        });
        int ans = 0;
        vector<int> dp(people.size() + 1, 0);
        for(int i = 0; i < people.size(); i++){
            dp[i] = people[i].score;
            for(int j = 0; j < i; j++){
                if(people[i].score >= people[j].score){
                    dp[i] = max(dp[j] + people[i].score, dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};