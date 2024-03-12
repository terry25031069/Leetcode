// https://leetcode.com/problems/remove-letter-to-equalize-frequency

class Solution{
public:
    static bool yee(int a, int b){
        if(a == 0) return false;
        return a < b;
    }
    bool check(string word){
        int a[26] = {};
        for(auto i: word){
            a[i - 'a']++;
        }
        sort(a, a + 26, yee);
        for(int i = 0; i < 26; i++) cout << a[i] << " \n"[i == 25];

};