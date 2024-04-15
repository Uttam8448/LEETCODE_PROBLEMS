class Solution {
public:
    int Solve(int target,vector<int> &num,vector<int>  &dp){
    if(target<0) {   return INT_MAX;}
    if(target==0){
        return 1;
    }
    if(dp[target]!=-1) return dp[target];
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int coins=Solve(target-num[i],num,dp);
        if(coins==INT_MAX)  coins=INT_MAX;
        else coins=1+coins;
        mini=min(mini,coins);
    }
    return dp[target]=mini;
}
    int coinChange(vector<int> &num, int x) {
        int n=num.size();
        vector<int>dp(x+1,-1);
        int ans=Solve(x,num,dp);
        if(ans==INT_MAX)  return -1;
        return ans-1;
    }
};