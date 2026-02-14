//BRUTE FORCE
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0; 
        int maxl = 0;
        for(int i = 0; i<n; i++){
            int zero = 0;
            for(int j = i; j<n; j++){
                if(nums[j]==0){
                    zero++;
                }
                if(zero>k){
                    break;
                }
                else{
                    len= j-i+1;
                    maxl = max(maxl, len);
                }
            }
        } 
        return maxl;
    }
};
------------------------------------------------------------------------------------------------
//OPTIMIZED SOLUTION O(2N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        int zeros = 0;
        int l = 0;
        int r = 0;
        while(r<n){
            if(nums[r] == 0){
                zeros++;
            }
            while(zeros>k){
                if(nums[l]==0){
                    zeros--;
                    l++;
                }
                else{
                    l++;
                }
            }
            if(zeros <= k){
                maxlen = max( maxlen , r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
