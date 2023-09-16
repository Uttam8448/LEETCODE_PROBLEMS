class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n%2==0){
            return false;
        }
        if(n==3 || n==1){
            return true;
        }
        else{
            double c=1;
            for(int i=1;i<sqrt(n);i++){
                if(c*3==n){
                    return true;
                }
                c=c*3;
            }
        }
        return false;
    }
};