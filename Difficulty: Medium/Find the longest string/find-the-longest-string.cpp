class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
         sort(words.begin(), words.end());
         
        unordered_map<string, int>ump;
        
        for(auto &i : words)
        ump[i]++;
//         {
//   "p":1, "pr":1, "pro":1, "problem":1,
//   "probl":1, "process":1, "processor":1, "pros":1
// }

        
        
        string s;   int l = 0;
        
        for(auto &i : words){
            string x;   
            int n = i.size();
            for(int j = 0; j < n; j++){
                x += i[j];
                if(!ump[x]){
                    n = 0;  break;
                }
            }
            if(n > l){
                s = i;  l = n;
            }
        }
        return s;
    }
};