class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0, i = 0, n = nums.size();
        while (i < n){
            if(nums[i] != val){
                nums[k] = nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};