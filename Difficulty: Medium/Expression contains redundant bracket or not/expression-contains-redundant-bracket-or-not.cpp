class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
         stack<char> st;
      for(char &ch: s){
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='(') 
        st.push(ch);
        else if(ch==')'){
          if(st.top() == '(') return true;
          while(st.top() != '(') st.pop();
          st.pop();
        }
      }
      
      return false;
    }
};
