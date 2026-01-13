class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = -1e18;

    // Search range decide karo
    for (auto &sq : squares) {
        double y = sq[1];
        double l = sq[2];
        low = min(low, y);        // lowest bottom
        high = max(high, y + l);  // highest top
    }

    // Binary search approx 60 iterations (precision ke liye)
    for (int it = 0; it < 60; it++) {
        double mid = (low + high) / 2.0;
        double above = 0.0, below = 0.0;

        for (auto &sq : squares) {
            double y = sq[1];
            double l = sq[2];

            // Case 1: line square ke neeche
            if (mid <= y) {
                above += l * l;
            }
            // Case 2: line square ke upar
            else if (mid >= y + l) {
                below += l * l;
            }
            // Case 3: line square ke beech
            else {
                below += (mid - y) * l;
                above += (y + l - mid) * l;
            }
        }

        // Binary search decision
        if (above > below) {
            low = mid;   // line ko upar le jao
        } else {
            high = mid;  // line ko neeche lao
        }
    }

    return low;
    }
};