class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>s;
        for(int i:a)
        {
            s.insert(i);
        }
        
        for(int i:b)
        {
            s.insert(i);
        }
        
 vector<int> result(s.begin(), s.end());
    return result;

    }
};