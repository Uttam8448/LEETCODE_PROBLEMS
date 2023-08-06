//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void printPermutation(string &str,int i,vector<string>& ans){
	if(i>=str.length()-1)
	{	ans.push_back(str);
		return;
	}
	//swapping
	for(int j=i;j<str.length();j++){
		swap(str[i],str[j]);
		printPermutation(str,i+1,ans);
		//to recreate the original input
		swap(str[j],str[i]); 
	}
        
    }
    
vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        printPermutation(S, 0 ,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends