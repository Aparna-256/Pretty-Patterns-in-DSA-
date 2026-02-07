class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        // 1️⃣ Find first index from left where order breaks
        while (left < n - 1 && nums[left] <= nums[left + 1]) {
            left++;
        }

        // Already sorted
        if (left == n - 1) return 0;

        // 2️⃣ Find first index from right where order breaks
        while (right > 0 && nums[right] >= nums[right - 1]) {
            right--;
        }

        // 3️⃣ Find min and max in the unsorted subarray
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = left; i <= right; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        // 4️⃣ Expand left boundary
        while (left > 0 && nums[left - 1] > mini) {
            left--;
        }

        // 5️⃣ Expand right boundary
        while (right < n - 1 && nums[right + 1] < maxi) {
            right++;
        }

        return right - left + 1;
    }
};
