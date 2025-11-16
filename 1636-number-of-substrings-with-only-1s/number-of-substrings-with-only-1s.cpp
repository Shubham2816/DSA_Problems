class Solution {
public:
    int numSub(string s) {
       int t=0, c=0, mod=1e9+7;

       for(char a:s){
        if(a=='1')
        c++;
        else
        c=0;
        t=(t+c)%mod;
       } 
       return t;
    }
};