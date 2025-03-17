class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>m;
         for (int i : nums) {
            m[i]++;
        }

for (const auto& i : m)
{
    if(i.second%2!=0)
    return 0;
}

return 1;
    }
};