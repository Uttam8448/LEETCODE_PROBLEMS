class Solution {
public:
        void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>>&grid, int& rowSize,int& columnSize){
        if(i<0 || j<0 || i>=rowSize || j>=columnSize){
            return;
        }
        if(visited[i][j]==0 && grid[i][j]=='1'){
            visited[i][j]=1;
            dfs(i-1,j,visited,grid,rowSize,columnSize);
            dfs(i,j-1,visited,grid,rowSize,columnSize);
            dfs(i,j+1,visited,grid,rowSize,columnSize);
            dfs(i+1,j,visited,grid,rowSize,columnSize);
        }
        else{
            return;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        int rowSize=grid.size();
        int columnSize=grid[0].size();
        vector<vector<int>> visited(rowSize,vector<int>(columnSize,0));
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<columnSize;j++){
                if(grid[i][j]=='1' && visited[i][j] == 0 ){
                    count++;
                    dfs(i,j,visited,grid,rowSize,columnSize);
                }
            }
        }
        return count;
    }
};