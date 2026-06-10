class Solution {
public:

    string mul(string s,char d,int zero){
      int i=s.size()-1;
      int digit = d-'0';
      string curr;

      int carry=0;

      while(i>=0 || carry){
         int n = (i>=0) ? (s[i]-'0') : 0;
         int digMul = (n*digit)+carry;
         carry=digMul/10;
         curr.push_back((digMul%10) + '0');
         i--;
      }

      reverse(curr.begin(),curr.end());
      return curr + string(zero,'0');
    }

    string add(string num1,string num2){
      int i=num1.length()-1;
      int j=num2.length()-1;
      int carry=0;

      string curr;

      while(i>=0 || j>=0 || carry){
        int n1 = (i>=0) ? (num1[i]-'0') : 0;
        int n2 = (j>=0) ? (num2[j]-'0') : 0;

        int addition = n1+n2+carry;
        curr.push_back((addition%10)+'0');
        carry=addition/10;
        i--;
        j--;
      }

      reverse(curr.begin(),curr.end());
      return curr;

    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
        return "0";

        if(num1.size()<num2.size())
        return multiply(num2,num1);

        int zero=0;
        string res="";

        for(int i=num2.size()-1;i>=0;i--){
           string curr = mul(num1,num2[i],zero);
           res=add(res,curr);
           zero++;
        }

        return res;
    }
};
