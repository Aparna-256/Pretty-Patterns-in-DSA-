class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left  = 0;
        int mid   = 0;
        int right = nums.size()-1;

        while(mid <= right){
            if(nums[mid] == 0){
                swap(nums[left], nums[mid]);
                mid++; //move mid to the right
                left++;
            }
            else if(nums[mid] == 2){
                swap(nums[right], nums[mid]);
                right--;//do not move mid...VERY IMPORTANT
            }
            else{
                mid++;
            }
        }
    }
};