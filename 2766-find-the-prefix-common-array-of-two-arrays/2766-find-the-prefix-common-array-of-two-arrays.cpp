class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       map<int,int> mp;
       int count=0;
       vector<int> ans;
       for(int i=0;i<A.size();i++){
            if(A[i]==B[i]){
                count++;
                mp[A[i]]=1;
            }
            else{
                if(mp.find(A[i])==mp.end()){
                mp[A[i]]=1;
                }
                else{
                    count++;
                }
                if(mp.find(B[i])==mp.end()){
                    mp[B[i]]=1;
                }
                else{
                    count++;
                }
            } 
            ans.push_back(count);
       } 
       return ans;
    }
};