class Solution {
public:
     void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<int>> &board,int &rowSize,int &colSize){
        if(board[i][j]==0)    return;
        if(visited[i][j])   return;
        visited[i][j]=1;
        if(i>0)
            dfs(i-1,j,visited,board,rowSize,colSize);
        if(i<rowSize-1)
            dfs(i+1,j,visited,board,rowSize,colSize);
        if(j>0)
            dfs(i,j-1,visited,board,rowSize,colSize);
        if(j<colSize-1)
            dfs(i,j+1,visited,board,rowSize,colSize); 
    }
    int numEnclaves(vector<vector<int>>& board) {
        int rowSize=board.size();
        int colSize=board[0].size();
        //checking for boundary O
        vector<vector<int>> visited(rowSize,(vector<int>(colSize,0)));
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(board[i][j]==1){
                    if(i==0 || j==0 || i==rowSize-1 || j==colSize-1){
                        if(visited[i][j])   continue;
                        dfs(i,j,visited,board,rowSize,colSize);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(visited[i][j])    continue;
                if(board[i][j]==1)    count++;
            }
        }
        return count;
    }
};