class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        //User function template for C++
int n = arr.size();
	   unordered_map<int,bool> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]*arr[i]]=1;
        }
        //  4: true,9: true,16: true,25: true,36: true
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp[arr[i]*arr[i] + arr[j]*arr[j]]==1 ) return true;
            }
        }
        return false;
        
    }
};