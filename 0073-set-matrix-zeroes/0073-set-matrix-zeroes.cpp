class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowSize=matrix.size();
        int colSize=matrix[0].size();
        bool b=false;
        int count=0;
        vector<vector<int>> visited(rowSize,vector<int>(colSize,0));
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(matrix[i][j]==0){
                    matrix[i][j]=-1;
                    visited[i][j]=1;
                    for(int k=0;k<matrix.size();k++){
                        if(matrix[k][j]!=0){
                            matrix[k][j]=-1;
                            visited[k][j]=1;
                        }
                    }
                    for(int k=0;k<matrix[0].size();k++){
                        if(matrix[i][k]!=0){
                            matrix[i][k]=-1;
                            visited[i][k]=1;
                        }
                    }
                }
            }
        }
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(matrix[i][j]==-1 && visited[i][j]==1)    matrix[i][j]=0;
                 
            }
        }
    }
};