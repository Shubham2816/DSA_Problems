class Solution {
public:

bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
         vector<int> primes;

        // Step 1: Find all primes in the range [left, right]
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }

         // Step 2: Find the closest prime pair
        if (primes.size() < 2) return {-1, -1}; // No pair found

        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};

         for (size_t i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primes[i - 1], primes[i]};
            }
        }

        return result;
    }
};