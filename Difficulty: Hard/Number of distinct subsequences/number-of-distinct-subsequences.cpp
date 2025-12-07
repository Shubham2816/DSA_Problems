class Solution {
  public:
    int distinctSubseq(string &s) {
        // code here
       /* 1. 2 options: use this character, do not use this character.
        :. dp[i]=2*dp[i-1]
        2. if there are duplicatyes
        
        RULE 1: Har new char subseq doubling karta hai → 2*dp[i-1]

RULE 2: Agar char pehle aa chuka, duplication remove karo
→ subtract dp[pehle wale ke just pehle]*/

int n=s.size();
const int m = 1e9 + 7;

vector<long long> dp(n+1,0);
dp[0]=1;

vector<int> l(256,-1);

for(int i=1;i<=n;i++)
{
    char c=s[i-1];
    dp[i]=(2*dp[i-1])%m;
    
    if(l[c]!=-1)
    dp[i]=(dp[i]-dp[l[c]-1]+m)%m;
    
    l[c]=i;
}
return (dp[n])%m;

    }
};