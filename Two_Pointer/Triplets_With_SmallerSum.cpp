class Solution {
public:
    long long countTriplets(int n, long long target, long long arr[]) {
        
        sort(arr, arr + n);
        long long count = 0;

        for(int i = 0; i < n - 2; i++) {
            
            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                long long currSum = arr[i] + arr[left] + arr[right];

                if(currSum < target) {
                    count += (right - left); // ⭐ key line
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return count;
    }
};
