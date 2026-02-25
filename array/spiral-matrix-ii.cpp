class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int round = 1, count = 1;
        int startx = 0, starty = 0;
        int mid = n / 2;

        while(round <= n / 2){
            int i = startx;
            int j = starty;

            for(j = starty; j < n - round; j++){
                res[i][j] = count++;
            }
            
            for(i = startx; i < n - round; i++){
                res[i][j] = count++;
            }
            
            for(; j > starty; j--){
                res[i][j] = count++;
            }

            for(; i > startx; i--){
                res[i][j] = count++;
            }

            startx++;
            starty++;
            round++;
        }

        if(n % 2){
            res[mid][mid] = n * n;
        }

        return res;
    }
};