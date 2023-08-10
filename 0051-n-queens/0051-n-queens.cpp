class Solution {
public:

    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> upperLeftDiagonalCheck;
    unordered_map<int,bool> bottomLeftDiagonalCheck;
    void printSolution(vector<vector<char>> &board,int n,vector<vector<string>>& ans){
        vector<string> temp;
        for(int i=0;i<n;i++){
            string output = "";
            for(int j=0;j<n;j++){
                   output.push_back(board[i][j]);
                }
            temp.push_back(output);
            }
        ans.push_back(temp);
    }
    bool isSafe(int row,int col,int n){
        if(rowCheck[row]==true){
        return false;
        }
        if(upperLeftDiagonalCheck[n-1+col-row]==true){
        return false;
        }
        if(bottomLeftDiagonalCheck[col+row]==true){
        return false;
        }
        return true;

    }
    void solve(vector<vector<char>> &board,int col,int n,vector<vector<string>>& ans){
        //base case
        if(col>= n){
            printSolution(board,n,ans);
            return;
        } 
        
        //ek case solve karna hai baaki recursionamhal lega
        for(int row =0 ;row<n;row++){
            if(isSafe(row,col,n)){
                //rakh do
                board[row][col]='Q';
                //recursion solution layega
                rowCheck[row]=true;
                upperLeftDiagonalCheck[n-1+col-row]=true;
                bottomLeftDiagonalCheck[col+row]=true;
                solve(board,col+1,n,ans);
                //backtrack
                board[row][col]='.';
                rowCheck[row]=false;
                upperLeftDiagonalCheck[n-1+col-row]=false;
                bottomLeftDiagonalCheck[col+row]=false;
            }
        }
    }   
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        int col=0;
        solve(board, col,n,ans);
        return ans;
    }
};