class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char check){
        for(int i=0;i<9;i++){
            if(board[row][i]==check || board[i][col]==check){
               return false; 
            }
        }
        int matCheckRow=3*(row/3);
        int matCheckCol=3*(col/3);
        for(int i=matCheckRow;i<(matCheckRow+3);i++){
            for(int j=matCheckCol;j<(matCheckCol+3);j++){
                if((i!=row || j!=col) && board[i][j]==check){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        bool ch=false;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char k='1';(k-'9')<=0;k++){
                        if(isSafe(board,i,j,k)){
                            board[i][j]=k;
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};