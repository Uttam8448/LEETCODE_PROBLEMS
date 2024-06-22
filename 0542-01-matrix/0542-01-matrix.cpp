class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      int rowSize=mat.size();
       int colSize=mat[0].size();
       vector<vector<int>> visited(rowSize,vector<int>(colSize,0));
        vector<vector<int>> dist(rowSize,vector<int>(colSize,-1));
        
       queue<pair<pair<int,int>,int>> q;
        
       for(int i=0;i<rowSize;i++){
        for(int j=0;j<colSize;j++){
            if(mat[i][j]==0){
                q.push(make_pair(make_pair(i,j),0));
                visited[i][j]=1;
                dist[i][j]=0;
            }
            else{
                visited[i][j]=0;
            }
        }
       }
       int delrow[]={-1,0,+1,0};
       int delcol[]={0,+1,0,-1};
       while(!q.empty()){
          pair<pair<int,int>,int> temp=q.front();
          q.pop();
          int firstIndex=temp.first.first;
          int secondIndex=temp.first.second;
          int step=temp.second;
          dist[firstIndex][secondIndex] = step;
          
          for(int i=0;i<4;i++){
              int nrow=firstIndex+delrow[i];
              int ncol =secondIndex + delcol[i];
              if(nrow >= 0 && nrow <rowSize && ncol >= 0 && ncol <colSize && visited[nrow][ncol] == 0){
                  visited[nrow][ncol] = 1;
                  q.push({{nrow,ncol},step+1});
              }
          }
       }
       return dist;
    }
};