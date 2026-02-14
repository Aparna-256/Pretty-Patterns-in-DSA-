class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //BRUTE FORCE
        int n = s.size();
        int maxlen = 0;

        for(int i = 0; i<n; i++){
            vector<int>freq(256, 0);
            for(int j = i; j<n; j++){
                if(freq[s[j]] != 0){
                    break;
                }
                else{
                    freq[s[j]]++;
                    maxlen = max(maxlen, j-i+1);
                }
            }
        }
        return maxlen;
    }
};

-----------------------------------------------------------------------------------------

//OPTIMIZED 0(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        int len = 0;
        int l = 0; 
        int r = 0;

        vector<int>freq(256, -1);

        while(r < n){
            if(freq[s[r]] == -1){
                freq[s[r]] = r;
                len = r-l +1;
                maxlen = max(maxlen, len);
            }
            else{
                if(freq[s[r]] >= l){
                    l = freq[s[r]] + 1;
                }
                len = r-l +1;
                maxlen = max(maxlen, len);
                freq[s[r]] = r;
            }
            r++;
        }
        return maxlen;
    }
};
