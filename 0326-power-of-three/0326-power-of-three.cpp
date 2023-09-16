class Solution {
public:
    bool isPowerOfThree(int n) {
        double c=n;
        for(int i=1;i<=sqrt(n)+1;i++){
            if(c==1)
                    return true;
            c=c/3;
            }
        return false;
    }
};