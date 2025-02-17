class Solution {
public:
    int numTilePossibilities(string tiles) {
           vector<int> count(26, 0);
        for (char ch : tiles) {
            count[ch - 'A']++;
        }
        return backtrack(count);
    }
     int backtrack(vector<int>& count) {
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                // Choose this character
                count[i]--;
                // Count the current sequence
                sum += 1;
                // Continue to form more sequences
                sum += backtrack(count);
                // Backtrack
                count[i]++;
            }
        }
        return sum;}
};