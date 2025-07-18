class Solution {
  public:
    int kokoEat(vector<int>& arr, int h) {
        // Code here
           int low=1;
        int high=*max_element(arr.begin(),arr.end());
        int ans=high;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            double total_hours=0;
            for(int banana:arr)
            {
                total_hours=total_hours+ceil((double)banana/mid);
            }
            if(total_hours<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};