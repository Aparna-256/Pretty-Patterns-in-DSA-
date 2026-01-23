class Solution {
public:
    void rearrange(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {

            // 0 is already in correct place
            if(nums[left] == 0) {
                left++;
            }
            // 1 is already in correct place
            else if(nums[right] == 1) {
                right--;
            }
            // nums[left] = 1 and nums[right] = 0
            else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
    }
};
