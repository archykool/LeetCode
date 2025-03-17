class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1){
            return {1};
        }

        vector<int> start(n);
        start[0] = nums[0];
        for(int i = 1; i < n; i++){
            start[i] = nums[i]*start[i-1];
        }

        vector<int> end(n);
        end[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            end[i] = nums[i] * end[i+1];
        }

        vector<int> ans(n);
        ans[0] = end[1];
        ans[n-1] = start[n-2];
        for(int i = 1; i < n-1; i++){
            ans[i] = end[i+1]*start[i-1];
        }
        return ans;
    }
};