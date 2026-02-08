class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
         long long m=INT_MIN;
	    long long st=1;
	    long long e=1;
	    
	    for(int i=0;i<n;i++)
	    {
	        st*=arr[i];   // 6  -18 180
	        e*=arr[n-i-1];  //2  0  -20
	        
	        long long a=max(st,e); // 6  0  180
	        
	        m=max(m,a);   // 6  0  180
	        if(st==0)st=1;
	        if(e==0)e=1;
	        
	    }
	    return m;
    }
};