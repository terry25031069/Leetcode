// https://leetcode.com/problems/image-smoother

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>>a(img.size(), vector<int>(img[0].size(), 0));
        int n = img.size(), m = img[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int sum = 0, cnt = 0;
                for(int dx = -1; dx < 2; dx++){
                    for(int dy = -1; dy < 2; dy++){
                        if(i + dx > -1 && i + dx < n && j + dy > -1 && j + dy < m){
                            sum += img[i + dx][j + dy];
                            cnt++;
                        }
                    }
                }
                //cout << i << ' ' << j << ' ' << sum << ' ' << cnt << endl;
                a[i][j] = sum / cnt;
            }
        }
        return a;
    }
};