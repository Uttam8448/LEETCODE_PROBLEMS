class Solution {
public:
    int countAsterisks(string s) {
        int c=0;
        int brace=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='|' && brace!=1) brace=1;
            else if(s[i]=='*' && brace!=1) c++;
            else if(s[i]=='|' && brace==1) brace=0;
        }
        return c;
    }
};