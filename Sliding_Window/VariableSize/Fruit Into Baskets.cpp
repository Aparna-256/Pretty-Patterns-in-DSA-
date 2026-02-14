class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        
        int n = fruits.size();
        int maxlen = 0;
        int l = 0; 
        int r = 0; 
        map<int, int>freq;

        for(r = 0; r<n; r++){
          freq[fruits[r]]++;

          if(freq.size()>2){
            while(freq.size()>2){
              freq[fruits[l]]--;

              if(freq[fruits[l]]==0){
                freq.erase(fruits[l]);
              }

              l++;
            }
          }
          else{
            maxlen =max(maxlen , r-l+1);
          }
        }
        return maxlen;
    }
};---------------------------------------------------------------------------------------//O(2n)
