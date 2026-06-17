class Solution {
public:
    int reverse(int x) {
        int n = abs(x);
        long ans = 0;
        int sign = (x<0)?-1:1;
  

        while(n>0){
          int lastDigit = n%10;
          ans=ans*10+lastDigit;
          n=n/10;
        }

        if(ans<INT_MIN || ans>INT_MAX)
        return 0;

        return sign*ans;
    }
};
