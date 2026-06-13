class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        int k = abs(n);
        double init = x;
        int cur = 1;
        while(2*cur<k){
            x = x * x;
            cur = 2*cur;
        }
        int left = k - cur;
        for(int i=0; i<left;i++){
            x *= init;
        }
        if(n<0) return 1/x;
        else return x;
        
    }
};
