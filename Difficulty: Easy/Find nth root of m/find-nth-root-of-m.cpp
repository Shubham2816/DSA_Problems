class Solution {
  public:
  
      long long power(long long x, int n, int m) {
          
        long long result = 1;
        for (int i = 0; i < n; ++i) {
            result *= x;
            if (result > m)
            return result;
        }
        return result;
        
    }
  
    int nthRoot(int n, int m) {
        // Code here.
          int low = 1;
        int high = m;
        int mid;
        long long val;
        
        
        
        
        while(high >= low){
            mid = (low + high)/2;
            val = power(mid,n,m);
            
            
//             mid = (1 + 9) / 2 = 5
// val = power(5, 2, 9) → 5 * 5 = 25 → > 9 → return 25
// val > m → high = 5 - 1 = 4
            
            if(val == m){
                return mid;
            }
            
            else if (val > m){
                high = mid -1;
            }
            
            else{
                low = mid + 1;
            }
            
        }
        
        return -1;
    }
};