class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, sum = 0, subLength = INT_MAX;
        int n = nums.size();
        for(int j = 0; j < n; j++){
            sum += nums[j];
            while(sum >= target){
                subLength = min(subLength, j - i + 1);
                sum -= nums[i++];                
            }
        }
        // return subLength;
        return (subLength != INT_MAX) ? subLength : 0 ;

    }
};