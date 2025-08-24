class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0, ans = 0, k = 0, count = 0;
        while(i < nums.size()){
            if(nums[i] == 0)
                k++;   
// total of 0 1 1 1 0 1 1 0 1
            // i  
            // j
            //         i
            // j         
            // j++
            // ans=4-0=4 so 4-1=3  
                          
            //               i
            //   j             
            //           j  
            //                  i



            while(k>1)
            {
                k-=(nums[j]==0);j++;
            }
            ans = max(ans,i-j);

            i++;
        }
        return ans;
    }
};