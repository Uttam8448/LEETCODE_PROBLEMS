//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s) {
        // code here
        stack<char> st;
        int size=s.size();
        int i=0;
        bool b=0;
        while(i<size){
            if(s[i]=='(' || s[i]=='+' || s[i] =='-' || s[i]=='*' || s[i]=='/'){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.top()!='('){
                    while(st.top()!='(' || st.empty()){
                        st.pop();
                    }
                    if(st.empty())  return 1;
                    else st.pop();
                }
                else{
                    return 1;
                }
            }
            i++;
        }
        if(st.empty()){
            return 0;
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends