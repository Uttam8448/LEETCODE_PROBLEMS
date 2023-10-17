//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
     stack<char> temp;
     int size=s.size();
     if(size%2){
         return -1;
     }
     else{
            int i=0;
            while(i<size){
                char curr=s[i];
                if(curr=='{'){
                    temp.push(curr);
                }
                else{
                    if(!temp.empty()){
                        if(temp.top()=='{'){
                            temp.pop();
                        }
                        else{
                            temp.push(curr);
                        }
                    }
                    else{
                        temp.push(curr);
                    }
                }
                i++;
            }
            int count=0;
            while(!temp.empty()){
                if(temp.top()=='{'){
                    count++;
                    temp.pop();
                    if(temp.top()=='{'){
                        temp.pop();
                    }
                    else{
                        count++;
                        temp.pop();
                    }
                }
                else{
                    temp.pop();
                    if(temp.top()=='{'){
                        temp.pop();
                    }
                    else{
                        count++;
                        temp.pop();
                    }
                }
                
            }
            return count;
     }
    
} 