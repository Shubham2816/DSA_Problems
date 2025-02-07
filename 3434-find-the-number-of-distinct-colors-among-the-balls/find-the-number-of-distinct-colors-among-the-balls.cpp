class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> sol;
        unordered_map<int, int> b; // Ball -> Color
        unordered_map<int, int> c; // Color -> Count
        int count = 0;

        for (auto& i : queries) {
            int ball = i[0], color = i[1];

            // Remove previous color if present
            if (b.find(ball) != b.end()) {
                int pc = b[ball];
                c[pc]--;

                // Only decrease the distinct color count if color becomes zero
                if (c[pc] == 0) {
                    count--;
                }
            }

            // Update the ball's color
            b[ball] = color;
            c[color]++;

            // Increase the distinct color count if it's a new color
            if (c[color] == 1) {
                count++;
            }

            sol.push_back(count);
        }

        return sol;
    }
};
