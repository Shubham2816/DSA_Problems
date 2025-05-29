class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
           vector<int>new_arr;
      
      for(int i = 0; i < arr.size(); i++){
          if(arr[i] >= 0){          //for positive element
              new_arr.push_back(arr[i]);
          }
      }
      
      for(int j = 0; j < arr.size(); j++){
          if(arr[j] < 0){              //for negative element
              new_arr.push_back(arr[j]);
          }
      }
      
      arr = new_arr;
    }
};