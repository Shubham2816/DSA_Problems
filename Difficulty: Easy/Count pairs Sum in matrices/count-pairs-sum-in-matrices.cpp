class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
           unordered_set<int> help;
        for (int i = 0; i < mat2.size(); i++) {
            for (int j = 0; j < mat2[0].size(); j++) {
                help.insert(mat2[i][j]);
            }
        }
        int cnt = 0;
        for (int i = 0; i < mat1.size(); i++) {
            for (int j = 0; j < mat1[0].size(); j++) {
                int omp = x - mat1[i][j];
                if (help.find(omp) != help.end())
                    cnt++;
            }
        }
        return cnt;
    }
};