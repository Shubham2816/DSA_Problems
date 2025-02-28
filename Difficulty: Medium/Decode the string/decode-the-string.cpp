//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
             stack<int> countStack;  // Stack to store repetition counts
    stack<string> strStack; // Stack to store intermediate results
    string currentStr = ""; // Stores the currently forming string
    int num = 0;            // Stores the current number

    for (char c : s) {
        if (isdigit(c)) { // If character is a digit, form the number
            num = num * 10 + (c - '0'); // Convert character to integer
        } else if (c == '[') { // Push current state and reset
            countStack.push(num);   // Store the current repeat count
            strStack.push(currentStr); // Store the string built so far
            num = 0; // Reset num for new numbers
            currentStr = ""; // Reset the current string
        } else if (c == ']') { // Decode the enclosed substring
            string temp = currentStr; // Store the repeated string part
            int repeatTimes = countStack.top(); // Get repeat count
            countStack.pop(); // Remove count from stack
            currentStr = strStack.top(); // Restore previous string
            strStack.pop(); // Remove from stack

            // Repeat the decoded string and append
            while (repeatTimes--) {
                currentStr += temp;
            }
        } else { // Normal character, add to currentStr
            currentStr += c;
        }
    }
    
    return currentStr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends