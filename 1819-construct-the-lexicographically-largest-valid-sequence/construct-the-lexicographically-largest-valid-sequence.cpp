class Solution {
public:

 bool backtrack(vector<int>& result, vector<bool>& used, int n, int index) {
        // Skip indices that are already filled
        while (index < result.size() && result[index] != 0) {
            index++;
        }

        // If index reaches the end of the result array, a valid sequence is constructed
        if (index == result.size()) {
            return true;
        }

        // Try placing numbers from n to 1 to get the lexicographically largest sequence
        for (int i = n; i >= 1; i--) {
            // If the number i is already used, skip it
            if (used[i]) continue;

            // Special case for 1 as it appears only once
            if (i == 1) {
                // Place 1 at the current index
                result[index] = 1;
                used[1] = true;

                // Recursively try to place the next numbers
                if (backtrack(result, used, n, index + 1)) return true;

                // Backtrack: Reset the current position and mark 1 as unused
                result[index] = 0;
                used[1] = false;
            } 
            // For numbers greater than 1, they must be placed twice with a distance of i
            else if (index + i < result.size() && result[index + i] == 0) {
                // Place the number at index and index + i
                result[index] = i;
                result[index + i] = i;
                used[i] = true;

                // Recursively continue to the next index
                if (backtrack(result, used, n, index + 1)) return true;

                // Backtrack: Reset both positions and mark the number as unused
                result[index] = 0;
                result[index + i] = 0;
                used[i] = false;
            }
        }
        // If no number can be placed at the current index, return false to backtrack
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
         // Initialize the result vector with 2 * n - 1 zeros (since the length of the sequence is 2 * n - 1)
        vector<int> result(2 * n - 1, 0);

        // A boolean array to keep track of which numbers have been used in the sequence
        vector<bool> used(n + 1, false);

        // Start the backtracking process from index 0
        backtrack(result, used, n, 0);
        
        // Return the lexicographically largest valid sequence
        return result;
    }
};