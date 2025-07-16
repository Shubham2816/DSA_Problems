class Solution {
  public:
   int maxKPower(int n, int k) {
        unordered_map<int, int> primePower;

        // Step 1: Prime factorize k
        for (int i = 2; i * i <= k; ++i) {
            while (k % i == 0) {
                primePower[i]++;
                k /= i;
            }
        }
        if (k > 1) {
            primePower[k]++;
        }

        int res = INT_MAX;

        // Step 2: For each prime, use Legendre’s formula
        for (auto it : primePower) {
            int p = it.first;
            int a = it.second;

            int count = 0;
            int temp = n;
            while (temp) {
                count += temp / p;
                temp /= p;
            }

            res = min(res, count / a);
        }

        return res;
    }
};