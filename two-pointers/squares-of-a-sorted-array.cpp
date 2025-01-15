class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int k = nums.size() - 1;
        
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                res[k] = nums[j] * nums[j];
                j--;
                k--;
            } else {
                res[k] = nums[i] * nums[i];
                k--;
                i++;
            }
        }
        return res;
    }
};