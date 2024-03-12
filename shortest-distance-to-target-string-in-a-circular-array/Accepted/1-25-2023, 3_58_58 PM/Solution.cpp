// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int idx) {
        int B = 100000000, N = words.size();
        int ans = B;
        for(int i = 0; i < N; i++){
            if(words[i] == target){
                int cnt = (i - idx + N) % N;
                int ccnt = (idx - i + N) % N;
                ans = min(ans, min(ccnt, cnt));
            }
        }
        if(ans == B) return -1;
        return ans;
    }
};