// https://leetcode.com/problems/add-strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size()) swap(num1, num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        while(num2.size() < num1.size()) num2 += '0';
        num1 += '0';
        for(int i = 0; i < num1.size() - 1; i++){
            num1[i] += num2[i] - '0';
            if(i < num1.size() - 1 && num1[i] - '0' > 9) num1[i + 1]++, num1[i] -= 10;
        }
        reverse(num1.begin(), num1.end());
        if(num1[0] == '0') num1 = num1.substr(1);
        return num1;
    }
};