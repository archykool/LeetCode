class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0; // beginning of the every round
        int loop = n/2; // round of matrix, control the while function
        int mid = n/2; // for special condition (n = odds)
        int count = 1; // fill in the nbr
        int offset = 1; // the shrinking of round
        int i, j; // moving indicator

        while(loop --) {
            i = startx;
            j = starty;

            for(j; j < n - offset; j++){
                res[i][j] = count++;
            }

            for(i; i < n - offset; i++){
                res[i][j] = count++;
            }

            for(j; j > starty; j--){
                res[i][j] = count++;
            }

            for(i; i > startx; i--){
                res[i][j] = count++;
            }

            // preparation for the new loop
            startx++;
            starty++;

            offset++;
        }

        // cover special cases
        if(n % 2){
            res[mid][mid] = count;
        }
        return res;
    }
};