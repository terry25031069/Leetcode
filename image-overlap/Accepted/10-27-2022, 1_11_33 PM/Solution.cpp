// https://leetcode.com/problems/image-overlap

class Solution {
public:
    int check(vector<vector<int>>& img1, vector<vector<int>>& img2, int shifth, int shiftv){
        int ans = 0, n = img1.size();
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i + shifth > -1 && i + shifth < n && j + shiftv > -1 && j + shiftv < n && img1[i + shifth][j + shiftv] == 1 && img2[i][j] == 1)
                ans++;
            }
        }
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans = 0, n = img1.size();
        for(int i = -n; i < n; i++){
            for(int j = -n; j < n; j++){
                ans = max(check(img1, img2, i, j), ans);
            }
        }
        return ans;

    }
};