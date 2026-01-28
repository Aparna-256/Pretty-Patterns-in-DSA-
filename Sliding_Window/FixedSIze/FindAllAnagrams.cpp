class Solution {
public:

    bool allZeroes(vector<int> &freq){
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {

        int n = s.size();
        int k = p.size();

        vector<int> ans;
        if(k > n) return ans;

        vector<int> freq(26, 0);

        for(char c : p){
            freq[c - 'a']++;
        }

        int left = 0;

        for(int right = 0; right < n; right++){

            freq[s[right] - 'a']--;

            if(right - left + 1 > k){
                freq[s[left] - 'a']++;
                left++;
            }

            if(right - left + 1 == k){
                if(allZeroes(freq)){
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};
