class Solution {
public:


    bool isPalindrome(int x) {
     if(x <0){
         return false;
     }
     int y=x;
    int a=0;
    long b=0; 
    while(x!=0){
        a=x%10;
        x=x/10;
        b=b*10+a;
    }
      if(b==y){
          return true;
      }   
       return false; 
    }
};