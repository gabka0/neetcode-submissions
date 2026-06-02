class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> x;
        while(n!=1){
            n = square(n);
            if(x.find(n)!=x.end()) return false;
            x.insert(n);
        }
        return true;

        
    }
    int square(int n){
        int sum = 0;
        while(n>=1){
            int temp = n % 10;
            sum +=  temp * temp;
            n = n/10;
        }
        return sum;
    }
};
