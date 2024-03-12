// https://leetcode.com/problems/implement-rand10-using-rand7

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = rand7(), b = rand7();
        while(a + b > 5){
            a = rand7(), b = rand7();
        }
        a--, b--;
        return (a > 0) * 4 + (a > 1) * 3 + (a > 2) * 2 + b;
    }
};