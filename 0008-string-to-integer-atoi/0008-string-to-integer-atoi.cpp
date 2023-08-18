class Solution {
public:
    int myAtoi(string s) {
        long int a=0;
        int i=0;
        int n=s.length();
        bool d=false;
        bool b=false;
        while(s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            b=true;
            i++;
        }
        else if(s[i]=='+' && i<n){
            d=true;
            i++;
        }
        while(i<n && 0<=s[i]-'0' && s[i]-'0'<=9){
            int digit=s[i]-'0';
            a=a*10+digit;
            if(a>INT_MAX && b!=true){
                return INT_MAX;
            }
            if(a>INT_MAX && b==true){
                return INT_MIN;
            }
            i++;
        }
        if(b){
            return -a;
        }
        return a;
    }
};