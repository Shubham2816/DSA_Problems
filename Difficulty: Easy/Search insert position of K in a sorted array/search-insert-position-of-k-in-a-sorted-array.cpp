class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
           int i;
        for(i=0; i<arr.size(); i++)
        {
            if(arr[i]==k)
            {
                return i;
            }
            else if(arr[i]>k)
            {
                return i;
            }
        }
        return i;
    }
};