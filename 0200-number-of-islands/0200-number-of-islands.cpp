class Solution {
public:
        void dfs(int i,int j,vector<vector<char>>&grid, int& rowSize,int& columnSize){
        if(i<0 || j<0 || i>=rowSize || j>=columnSize){
            return;
        }
        if(grid[i][j]=='1'){
            grid[i][j]='0';
            dfs(i-1,j,grid,rowSize,columnSize);
            dfs(i,j-1,grid,rowSize,columnSize);
            dfs(i,j+1,grid,rowSize,columnSize);
            dfs(i+1,j,grid,rowSize,columnSize);
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
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<columnSize;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,rowSize,columnSize);
                }
            }
        }
        return count;
    }
};