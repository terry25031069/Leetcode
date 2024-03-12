// https://leetcode.com/problems/day-of-the-week

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        int tmp = 0, i;
        for(i = 1971; i < year; i++){
            tmp += 365 + (i % 4 == 0 && i % 100|| i % 400 == 0);
        }
        vector<int> mon = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(i % 4 == 0 && i % 100 || i % 400 == 0) mon[2]++;
        for(int i = 1; i < 13; i++){
            mon[i] += mon[i-1];
        }
        tmp += mon[month - 1];
        tmp += day + 4;
        cout << tmp << endl;
        tmp %= 7;
        vector<string> ans{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return ans[tmp];
    }
};