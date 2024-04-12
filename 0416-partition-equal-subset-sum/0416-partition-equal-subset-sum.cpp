class Solution {
public:
    bool Solve(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
        if(target==0)	return true;
        //mistake prone
        if(ind==0)	return (arr[0]==target);
        if(dp[ind][target]!=-1)	return dp[ind][target];
        int notPick=Solve(ind-1,target,arr,dp);
        int pick=false;
        if(arr[ind]<=target)	pick=Solve(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]=pick||notPick;
    }
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum%2==1)	return false;
        int target=sum/2;
        vector<vector<int>> dp(n,vector<int> (target+1,-1));
        return Solve(n-1,target,arr,dp);
    }
};