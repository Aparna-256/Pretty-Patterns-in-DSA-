class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0, j = 0;
        queue<int> q;       // stores negative elements
        vector<int> ans;
        
        while (j < n) {
            
            // Step 1: Check if current element is negative
            if (arr[j] < 0) {
                q.push(arr[j]);
            }
            
            // Step 2: If window size < k → expand
            if (j - i + 1 < k) {
                j++;
            }
            
            // Step 3: If window size == k → process
            else if (j - i + 1 == k) {
                
                // If queue empty → no negative number
                if (q.empty()) {
                    ans.push_back(0);
                } else {
                    ans.push_back(q.front());
                    
                    // Remove element if it's going out of window
                    if (arr[i] == q.front()) {
                        q.pop();
                    }
                }
                
                // Slide window
                i++;
                j++;
            }
        }
        
        return ans;
    }
};
