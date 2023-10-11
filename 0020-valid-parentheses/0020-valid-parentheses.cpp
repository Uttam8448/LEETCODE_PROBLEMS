class Solution {
public:
    bool isValid(string s) {
        stack<char> st1;
        stack<char> st2;
        stack<char> st3;
        int size=s.size();
        int i=0;
        while(i<size){
            if(s[i]=='{'){
                st1.push('{');
            }
            else if(s[i]=='}'){
                if(st1.empty()) return false;
                if(st1.top()=='{')
                    st1.pop();
                else return false;
            }
            else if(s[i]=='('){
                st1.push('(');
            }
            else if(s[i]==')'){
                if(st1.empty()) return false;
                if(st1.top()=='(')
                    st1.pop();
                else return false;
            }
            else if(s[i]=='['){
                st1.push('[');
            }
            else if(s[i]==']'){
                if(st1.empty()) return false;
                if(st1.top()=='[')
                    st1.pop();
                else return false;
            }
            i++;
        }
        if(st1.empty()){
            return true;
        }
        return false;
    }
};