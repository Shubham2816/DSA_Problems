#include <vector>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Step 1: Create a sieve to mark primes
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Collect primes in the range [left, right]
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        // Step 3: Find the closest prime pair
        if (primes.size() < 2) return {-1, -1}; // No pair found

        int minDiff = 1e9;
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
