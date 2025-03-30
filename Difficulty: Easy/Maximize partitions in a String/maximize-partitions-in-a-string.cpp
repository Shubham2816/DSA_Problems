//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
       vector<int> last(26,-1);
        int n=s.length();
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        
        int end=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            end = max(end, last[s[i]-'a']);
            if(i==end){
                cnt++;
            }
        }
        return cnt;
    }
};



// Step 1: Initialize last array
// last keeps track of the last occurrence of each character in the string.

// First loop: Iterate over s to populate last.

// Loop 1: Finding the last occurrence of each character
// i	s[i]	last[s[i] - 'a'] = i	last array after update
// 0	'a'	last[0] = 0	last = [0, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _]
// 1	'c'	last[2] = 1	last = [0, _, 1, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _]
// 2	'b'	last[1] = 2	last = [0, 2, 1, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _]
// 3	'b'	last[1] = 3	last = [0, 3, 1, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _]
// 4	'c'	last[2] = 4	last = [0, 3, 4, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _]
// 5	'c'	last[2] = 5	last = [0, 3, 5, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _]
// Final last array:
// last = [0, 3, 5, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _, _]


// Step 2: Find the partitions
// end keeps track of the farthest last occurrence of any character encountered so far.

// cnt counts the partitions.

// Loop 2: Traversing s
// i	s[i]	end = max(end, last[s[i]-'a'])	end after update	cnt update if i == end
// 0	'a'	max(0, last[0]=0)	0	✅ cnt = 1 (Partition at i = 0)
// 1	'c'	max(0, last[2]=5)	5	❌
// 2	'b'	max(5, last[1]=3)	5	❌
// 3	'b'	max(5, last[1]=3)	5	❌
// 4	'c'	max(5, last[2]=5)	5	❌
// 5	'c'	max(5, last[2]=5)	5	✅ cnt = 2 (Partition at i = 5)





//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends