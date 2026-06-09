class Solution {
public:

    int sumOfSquareDigits(int n){
        int ans = 0;
        while(n){
            int last = n%10;
            ans+=last*last;
            n=n/10;
        }

        return ans;
    }

    bool isHappy(int n) {
       unordered_set<int> s;

       while(n!=1){
        s.insert(n);
        n=sumOfSquareDigits(n);
        if(s.find(n)!=s.end())
        return false;
       }

       return true;
    }
};
