class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int minLen=INT_MAX;
        
        int sum=0;
        while(j<n){
          sum=sum+nums[j];

        //   minimise the length of window
          while(sum>=target){
            minLen=min(minLen,j-i+1);
            sum=sum-nums[i];
            i++;
          }
          j++;
        }
return minLen==INT_MAX?0:minLen;
    }   
};