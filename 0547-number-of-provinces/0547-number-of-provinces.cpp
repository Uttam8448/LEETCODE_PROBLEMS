class Solution {
public:
    void dfs(int node,vector<int> &visited,vector<vector<int>>& isConnected,int n){
        if(!visited[node]){
            visited[node]=1;
        }
        else{
            return;
        }
        for(int i=0;i<n;i++){
            if(node==i) continue;
            if(isConnected[node][i]==1)
                dfs(i,visited,isConnected,n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]!=1){
                count++;
                dfs(i,visited,isConnected,n);
            }
        }
        return count;
    }
}; 