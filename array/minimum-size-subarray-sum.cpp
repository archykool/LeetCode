class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int k = 0, sum = 0;
        int res = INT32_MAX;
        for(int i = 0; i < nums.size(); i++) {
            sum = 0;
            for(int j = i; i < nums.size(); j++){
                sum += nums[j];
                if(sum > target){
                    k = j - i + 1;
                    res = res < k ? res : k;
                    break;
                }
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};