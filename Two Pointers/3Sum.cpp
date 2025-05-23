class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
      
      int n=nums.size();
      sort(nums.begin(),nums.end());
      set<vector<int>> s;
        vector<vector<int>> output;
        
        for(int i=0; i<n; i++){
           int j=i+1;
           int k=n-1;
           while(j<k){
         int sum=nums[i]+nums[j]+nums[k];
         if(sum==0){
             s.insert({nums[i],nums[j],nums[k]});
             j++;
             k--;
         }else if(sum<0){
             j++;
                    }else{
                        k--;
             
        }
           }
        }
                  for(auto triplets:s)
                  output.push_back(triplets);
                  return output;
                
              }
      
      };