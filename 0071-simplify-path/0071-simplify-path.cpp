class Solution {
public:
    void buildans(stack<string>&st,string &ans){
        if(st.empty()){
            return;
        }
        string minpath=st.top(); 
        st.pop();
        buildans(st,ans);
        ans+=minpath;       
    }
    
    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        while(i<path.size()){
            int start = i;
            int end = i+1;
            string file;
            while(end<path.size() && path[end]!='/'){
                end++;
            }
            string minPath = path.substr(start,end-start);
            i=end;
            if(minPath == "/" || minPath=="/."){
                continue;
            }
            if(minPath != "/.."){
                st.push(minPath);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        string ans=st.empty()?"/":"";
        buildans(st,ans);
        return ans;
    }
};