//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		   vector<string>v;
		   int n=s.length();
		   int p=(1<<n);
		   for(int i=0;i<p;i++){
            string a="";
		      for(int j=0;j<n;j++){
		        if((i&(1<<j))!=0)
		                a+=s[j];
		      }
            v.push_back(a);
		   }
        sort(v.begin(),v.end());
        vector<string>::iterator it;
        it = v.begin();
        v.erase(it);
        return v;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends