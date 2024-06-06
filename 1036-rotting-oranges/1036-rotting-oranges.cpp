class Solution {
public:
    // int dfs(){
    //     if(i<0 || j<0 || i>=rowSize || j>=columnSize){
    //         return 0;
    //     }

    //     if(visited[i][j]==0 && grid[i][j]==1){
    //         visited[i][j]=1;
    //         grid[i][j]=2;
    //     }
    //     int a=dfs(i+1,j,visited,grid,rowSize,colSize);
    //     int b=dfs(i-1,j,visited,grid,rowSize,colSize);
    //     int c=dfs(i,j+1,visited,grid,rowSize,colSize);
    //     int d=dfs(i,j-1,visited,grid,rowSize,colSize);
    //     if(a||b||c||d){
    //         count++;
    //         return 1;
    //     }
    //     return 0;
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        int rowSize=grid.size();
        int colSize=grid[0].size();
        int freshCount=0;
        vector<vector<int>> visited(rowSize,vector<int>(colSize,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<rowSize;i++){
            for(int j=0;j<colSize;j++){
                if(grid[i][j]==2){
                    pair<int,int> temp=make_pair(i,j);
                    pair<pair<int,int>,int> temp2=make_pair(temp,0);
                    q.push(temp2);
                    visited[i][j]=2;
                }
                else if(grid[i][j]==1){
                    freshCount++;
                    visited[i][j]=1;
                }
            }
        }
        int timeCount=0;
        int timeHopped=0;
        while(!q.empty()){
            pair<pair<int,int>,int> queuePopped=q.front();
            q.pop();
            int firstIndex=queuePopped.first.first;
            int secondIndex=queuePopped.first.second;
            timeHopped=queuePopped.second;
            if(firstIndex>0 && grid[firstIndex-1][secondIndex]==1 && visited[firstIndex-1][secondIndex]==1){
                pair<int,int> temp=make_pair(firstIndex-1,secondIndex);
                pair<pair<int,int>,int> temp2=make_pair(temp,timeHopped+1);
                freshCount--;
                visited[firstIndex-1][secondIndex]=2;
                q.push(temp2);
            }
            if(firstIndex<rowSize-1 && grid[firstIndex+1][secondIndex]==1 && visited[firstIndex+1][secondIndex]==1){
                pair<int,int> temp=make_pair(firstIndex+1,secondIndex);
                pair<pair<int,int>,int> temp2=make_pair(temp,timeHopped+1);
                visited[firstIndex+1][secondIndex]=2;
                freshCount--;
                q.push(temp2);
            }
            if(secondIndex>0 && grid[firstIndex][secondIndex-1]==1 && visited[firstIndex][secondIndex-1]==1){
                pair<int,int> temp=make_pair(firstIndex,secondIndex-1);
                pair<pair<int,int>,int> temp2=make_pair(temp,timeHopped+1);
                visited[firstIndex][secondIndex-1]=2;
                freshCount--;
                q.push(temp2);
            }
            if(secondIndex<colSize-1 && grid[firstIndex][secondIndex+1]==1 && visited[firstIndex][secondIndex+1]==1){
                pair<int,int> temp=make_pair(firstIndex,secondIndex+1);
                pair<pair<int,int>,int> temp2=make_pair(temp,timeHopped+1);
                visited[firstIndex][secondIndex+1]=2;
                freshCount--;
                q.push(temp2);
            }
        }
        return freshCount==0?timeHopped:-1;
    }
};