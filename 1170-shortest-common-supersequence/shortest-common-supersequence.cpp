class Solution {
public:

int t[1001][1001];

    int LCS(string &s,string &r,int n,int m)
    {
        if(n==0||m==0){
            return 0;
        }
        else if(t[n][m]!=-1){
            return t[n][m];
        }
        else if(s[n-1]==r[m-1]){
            return t[n][m]=LCS(s,r,n-1,m-1)+1;
        }
        else{
            return t[n][m]=max(LCS(s,r,n-1,m),LCS(s,r,n,m-1));
        }
    }


    string shortestCommonSupersequence(string s, string r) {
    memset(t,-1,sizeof(t));


    int i=s.size();
    int j=r.size();

    int x=LCS(s,r,i,j);

    string v;

    while(i > 0 && j > 0){
        if(s[i-1]==r[j-1]){
            v.push_back(s[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                v.push_back(s[i-1]);
                i--;
            }else{
                v.push_back(r[j-1]);
                j--;
            }
        }         
    }
    
    while(i > 0){
        v.push_back(s[i-1]);i--;
    }

    while(j > 0){
        v.push_back(r[j-1]);j--;
    }

    reverse(v.begin(),v.end());

    return v;
    }
};