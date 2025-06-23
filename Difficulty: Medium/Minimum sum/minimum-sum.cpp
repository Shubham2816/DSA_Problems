class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
       int n=arr.size();
        string x,y,num;
        sort(arr.begin(), arr.end());
        for(int i=0; i<n; i++){
            if(i%2==0){
                x+=to_string(arr[i]);
            }else{
                y+=to_string(arr[i]);
            }
        }
        
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        // cout<<x<<" "<<y<<endl;
        int sum=0, carry=0, i=0;
        while(i<x.size() && i<y.size()){
            sum=(x[i]-'0')+(y[i]-'0')+carry;
            num+=to_string(sum%10);
            carry=sum/10;
            i++;
        }
        if(i==x.size() && i==y.size()) num+=to_string(carry);
        while(i<x.size()){
            sum=(x[i]-'0')+carry;
            num+=to_string(sum%10);
            carry=sum/10;
            i++;
        }
        
        while(i<y.size()){
            sum=(y[i]-'0')+carry;
            num+=to_string(sum%10);
            carry=sum/10;
            i++;
        }
        reverse(num.begin(), num.end());
        i=0;
        while(num[i]=='0'){
            i++;
        }
        num=num.substr(i, num.size());
        return num;
    }
};