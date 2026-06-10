class Solution {
public:

    double calc(double x,int p){

        if(p==0)
        return 1;

        if(p==1)
        return x;

        double half = calc(x,p/2);
        double res = 1;

        if(p%2==0)
        res=half*half;

        else
        res=x*half*half;

        return res;
    }
    double myPow(double x, int n) {
        if(n==0)
        return 1;

        if(n==1)
        return x;

        int p = abs(n);

        double res = calc(x,p);

        return n>0 ? res : 1/res;
    }
};
