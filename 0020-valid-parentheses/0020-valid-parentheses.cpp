class Solution {
public:
    bool isValid(string s) {
        stack<char> st1;
        int size=s.size();
        int i=0;
        while(i<size){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st1.push(s[i]);
            }
            else{
                if(st1.empty()){
                    return false;
                }
                else{
                    if(s[i]=='}')
                        if(st1.top()=='{')
                            st1.pop();
                        else return false;
                    if(s[i]==']')
                        if(st1.top()=='[')
                            st1.pop();
                        else return false;
                    if(s[i]==')')
                        if(st1.top()=='(')
                            st1.pop();
                        else return false;
                }
            }
            i++;
        }
        if(st1.empty()){
            return true;
        }
        return false;
    }
};