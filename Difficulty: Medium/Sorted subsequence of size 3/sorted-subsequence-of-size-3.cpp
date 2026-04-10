// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
          int n=arr.size();
       int x[n]={0};
       int y[n]={0};
       x[0]=arr[0],y[n-1]=arr[n-1];
       for(int i=1;i<n;i++){
           x[i]=min(x[i-1],arr[i]);
           y[n-i-1]=max(y[n-i],arr[n-i-1]);
       }
       vector<int>v;
       for(int i=1;i<n-1;i++){
           if(x[i-1]<arr[i]&&arr[i]<y[i+1]) 
           v={x[i-1],arr[i],y[i+1]};
       }
       return v;
    }
};
