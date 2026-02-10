
class Solution {
  public:
    int countOfElements(int x, vector<int> &arr) {

        // Code Here
        int count = 0;
        for(int ele : arr){
            if(ele <= x){
                count++;
            }
        }
        return count;
    }
};