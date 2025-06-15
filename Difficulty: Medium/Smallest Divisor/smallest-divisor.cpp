class Solution {
  public:
  
  int computeSum(const vector<int>& arr, int divisor) {
    int sum = 0;
    for (int num : arr) {
        sum += (num + divisor - 1) / divisor; // Efficient ceil(num / divisor)
    }
    return sum;
}
  
  
  
    int smallestDivisor(vector<int>& arr, int k) {
         int left = 1;
    int right = *max_element(arr.begin(), arr.end());
    
     int answer = right;
     
      while (left <= right) {
        int mid = left + (right - left) / 2;
        int sum = computeSum(arr, mid);

        if (sum <= k) {
            answer = mid;
            right = mid - 1; // Try smaller divisor
        } else {
            left = mid + 1;  // Try larger divisor
        }
    }

    return answer;
        
        
//         low = 1
// high = max(arr) = 9



// mid = (1 + 9) // 2 = 5

// Check sum of ceil(arr[i] / 5):

// makefile
// Copy
// Edit
// arr:  [1, 2, 5, 9]
// ceil: [1, 1, 1, 2]  → sum = 5
// ✅ sum = 5 ≤ 6 → this divisor works,

//  high = mid - 1 = 4
 
 
//  mid = (1 + 4) // 2 = 2

// Ceil(arr[i] / 2):

// makefile
// Copy
// Edit
// arr:  [1, 2, 5, 9]
// ceil: [1, 1, 3, 5]  → sum = 10
// ❌ sum = 10 > 6 → too big → need larger divisor

// ➡️ low = mid + 1 = 3


    }
};
