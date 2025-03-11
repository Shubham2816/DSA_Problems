class Solution {
public:
    int numberOfSubstrings(string s) {
        int c[3] ={},ans=0,i=0,j=0;
        int n = s.length();
        for(;j<n;j++) 
        {
            c[s[j] - 'a']++;
            while (c[0] && c[1] && c[2])
             c[s[i++] - 'a']--;// making sure a, b , c is there
             ans+=i;
        }
        return ans;
    }
};


// c = [0, 0, 0], ans = 0, i = 0, j = 0

// Step-by-Step Execution:

// j = 0 (s[j] = 'a')

// Increment c[0]: c = [1, 0, 0]
// c[0], c[1], and c[2] are not all non-zero, so we skip the while loop.
// No substrings counted in this iteration.
// ans = 0
// j = 1 (s[j] = 'b')

// Increment c[1]: c = [1, 1, 0]
// c[0], c[1], and c[2] are not all non-zero, so we skip the while loop.
// No substrings counted in this iteration.
// ans = 0
// j = 2 (s[j] = 'c')

// Increment c[2]: c = [1, 1, 1]
// Now, c[0], c[1], and c[2] are all non-zero, so we enter the while loop:
// Slide i from 0 to 1, decrement c[0]: c = [0, 1, 1]
// Exit the while loop (we no longer have all three characters).
// Count substrings ending at j = 2 that start at or before i = 1: ans += i (1)
// ans = 1
// j = 3 (s[j] = 'a')

// Increment c[0]: c = [1, 1, 1]
// c[0], c[1], and c[2] are all non-zero, so we enter the while loop:
// Slide i from 1 to 2, decrement c[1]: c = [1, 0, 1]
// Exit the while loop.
// Count substrings ending at j = 3 that start at or before i = 2: ans += i (2)
// ans = 3
// j = 4 (s[j] = 'b')

// Increment c[1]: c = [1, 1, 1]
// c[0], c[1], and c[2] are all non-zero, so we enter the while loop:
// Slide i from 2 to 3, decrement c[2]: c = [1, 1, 0]
// Exit the while loop.
// Count substrings ending at j = 4 that start at or before i = 3: ans += i (3)
// ans = 6
// j = 5 (s[j] = 'c')

// Increment c[2]: c = [1, 1, 1]
// c[0], c[1], and c[2] are all non-zero, so we enter the while loop:
// Slide i from 3 to 4, decrement c[0]: c = [0, 1, 1]
// Exit the while loop.
// Count substrings ending at j = 5 that start at or before i = 4: ans += i (4)
// ans = 10