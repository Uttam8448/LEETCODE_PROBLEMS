class Solution {
public:
    string removeDuplicates(string s) {
        int i=0;
        stack<char> ans;
        while(s.length()>i){
            if(!ans.empty()){
                if(ans.top()==s[i]){
                    ans.pop();
                }
                else{
                    ans.push(s[i]);
                   
                }
            }
            else{
                ans.push(s[i]);
            }
             i++;
        }
        string ans1="";
        while(!ans.empty()){
            ans1.push_back(ans.top());
            ans.pop();
        }
        reverse(ans1.begin(),ans1.end());
        return ans1;
    }
};