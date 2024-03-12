// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int a[401] = {};
        for(int i = 0; i < num1.size(); i++){
            for(int j = 0; j < num2.size(); j++){
                a[i + j] += (num1[i] - '0') * (num2[j] - '0');
                if(a[i + j] > 9) a[i + j + 1] += a[i + j] / 10, a[i + j] %= 10;
            }
        }
        for(int i = 0; i < num1.size() + num2.size(); i++){
            cout << a[i] << " \n"[i == num1.size() + num2.size() - 1];
        }
        string ans = "";
        int flag = 0;
        for(int i = num1.size() + num2.size(); i >= 0; i--){
            if(flag == 0 && a[i]) flag = 1;
            if(flag)ans += char(a[i] + '0');
        }
        return ans;
    }
};