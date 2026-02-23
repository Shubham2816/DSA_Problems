class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>v;

        for(int i=0; i+k<=s.size();i++)
        {
            v.insert(s.substr(i, k));
        }

        return v.size() == (int)pow(2, k);

    }
};