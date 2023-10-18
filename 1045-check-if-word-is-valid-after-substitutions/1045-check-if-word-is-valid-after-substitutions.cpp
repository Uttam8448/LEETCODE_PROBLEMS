class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        if(s[0]!='a'){
            return false;
        }
        while(i<s.size()){
            if(s[i]=='a'){
                st.push(s[i]);
            }
            if(!st.empty()){
            if(s[i]=='b' && st.top()=='a'){
                st.push('b');
            }
            else if(s[i]=='b' && st.top()!='a'){
                return false;
            }
            if(s[i]=='c' && st.top()=='b'){
                st.pop();
                if(st.top()=='a'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='c' && st.top()!='b'){
                return false;
            }}
            i++;
        }
        if(st.empty()){
            return true;
        }
        return false; 
    }
};