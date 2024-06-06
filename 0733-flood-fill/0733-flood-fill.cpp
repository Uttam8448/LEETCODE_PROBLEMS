class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rowSize=image.size();
        int colSize=image[0].size();
        int startColor=image[sr][sc];
        vector<vector<int>> visited(rowSize,vector<int>(colSize,-1));
        
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        while(!q.empty()){
            pair<int,int> queuePopped=q.front();
            q.pop();
            int i=queuePopped.first;
            int j=queuePopped.second;
            if(i>0 && visited[i-1][j]==-1 && image[i-1][j]==startColor){
                q.push(make_pair(i-1,j));
                visited[i-1][j]=color;
            }
            if(i<rowSize-1 && visited[i+1][j]==-1 && image[i+1][j]==startColor){
                q.push(make_pair(i+1,j));
                visited[i+1][j]=color;
            }
            if(j>0 && visited[i][j-1]==-1 && image[i][j-1]==startColor){
                q.push(make_pair(i,j-1));
                visited[i][j-1]=color;
            }
            if(j<colSize-1 && visited[i][j+1]==-1 && image[i][j+1]==startColor){
                q.push(make_pair(i,j+1));
                visited[i][j+1]=color;
            }
        }
        visited[sr][sc]=color;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(visited[i][j]!=color){
                    visited[i][j]=image[i][j];
                }
            }
        }
        return visited;
    }
};