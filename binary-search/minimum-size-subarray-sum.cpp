class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, k = 0;
        int res = INT32_MAX;
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while (sum >= target) {
                k = j - i + 1;
                res = res < k ? res : k;
                sum -= nums[i]; // key of slide window
                i++;
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};