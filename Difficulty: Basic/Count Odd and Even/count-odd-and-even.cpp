class Solution {
  public:
    /*Function to count even and odd elements in the array
     * arr : Array with its elements
     */
    pair<int, int> countOddEven(vector<int> &arr) {
        // your code here
          int count1 = 0, count2 = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]% 2 != 0){
                count1++;
            }else{
                count2++;
            }
        }
        return {count1,count2};
    }
};