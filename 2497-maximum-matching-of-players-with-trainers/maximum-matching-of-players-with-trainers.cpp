// if p<=t match them 
// each p and t can be matched most once


// sort them so no wastage of higher capacity


class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());

int c=0;
int i=0,j=0;

while(i<p.size() && j<t.size())
{
    if(p[i]<=t[j])
    {
        c++;i++;j++;
    }
    else
    {
        j++;
    }
}
return c;

    }
};