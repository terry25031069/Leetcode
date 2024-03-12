// https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0

class Solution {
public:
    int minOperations(int n) {
       int ans = 0;
       for(int i = 0; (n >> i) > 0; i++){
           if(((n >> i) + 1) % 4 == 0){
               ans++, n += (1 << i);
               cout << i << endl;
           }
       } 
       bitset<18> b(n);
       return ans + b.count();
    }
};