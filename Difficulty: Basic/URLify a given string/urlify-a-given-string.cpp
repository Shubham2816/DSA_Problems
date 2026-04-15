class Solution {
  public:
    string URLify(string &s) {
        // code here
        string ans="";
        for(char &ch:s){
            if(ch==' ') ans+="%20";
            else ans+=ch;
        }
        return ans;
    }
};