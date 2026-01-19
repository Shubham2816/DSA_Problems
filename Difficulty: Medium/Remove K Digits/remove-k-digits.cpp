class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        vector<char> st;

        for (char c : s) {
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // If k digits still left to remove, remove from end
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Build result string and remove leading zeros
        string result;
        int i = 0;
        while (i < st.size() && st[i] == '0') i++;

        for (; i < st.size(); i++) {
            result.push_back(st[i]);
        }

        return result.empty() ? "0" : result;
    }
};