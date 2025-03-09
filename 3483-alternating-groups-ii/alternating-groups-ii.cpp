class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));
        int count = 0;
        int left = 0;
        
        for (int right = 0; right < colors.size(); ++right) {
            if (right > 0 && colors[right] == colors[right - 1]) {
                left = right;  
            }
            
            if (right - left + 1 >= k) {
                count++;  
            }
        }
        
        return count;
    }
};
// Expanded:   [0,1,0,1,0,0,1]

// right	colors[right]	Condition (colors[right] == colors[right - 1]?)	left Update	Window Size (right - left + 1)	count Update
// 0	0	No (first element)	-	1	-
// 1	1	No	-	2	-
// 2	0	No	-	3	count = 1
// 3	1	No	-	4	count = 2
// 4	0	No	-	5	count = 3
// 5	0	Yes (colors[5] == colors[4])	left = 5	1	-
// 6	1	No	-	2	-