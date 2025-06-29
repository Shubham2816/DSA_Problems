class Solution {
  public:
  
  bool isPossible(int H, vector<int>& arr, int k, int w) {
    int n = arr.size();
    vector<int> water(n + 1, 0);
    int used = 0, curr = 0;

    for (int i = 0; i < n; ++i) {
        curr += water[i];

        int height = arr[i] + curr;
        if (height < H) {
            int delta = H - height;
            used += delta;
            if (used > k) return false;

            curr += delta;
            water[i] += delta;
            if (i + w < n) water[i + w] -= delta;
        }
    }

    return true;
}
  
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
       int low = *min_element(arr.begin(), arr.end());
    int high = low + k, ans = low;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid, arr, k, w)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;}
    
};