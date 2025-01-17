class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n =derived.size();

        int sol=0;
        for(int i=0;i<n;i++)
        sol^=derived[i];
        return sol==0;
    }
};