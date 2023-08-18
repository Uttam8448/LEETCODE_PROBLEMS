class Solution {
public:
    int maxSumArrayHelper(vector<int>& v,int s,int e){
        if(s==e){
            return v[s];
        }
        int leftBorderSum=0,rightBorderSum=0;
        int maxLeftBorderSum=INT_MIN,maxRightBorderSum=INT_MIN;
        int mid=s+(e-s)/2;

        int maxLeftSum=maxSumArrayHelper(v,s,mid);
        int maxRightSum=maxSumArrayHelper(v,mid+1,e);


        for(int i=mid;i>=s;i--){
            leftBorderSum+=v[i];
            if(maxLeftBorderSum<leftBorderSum){
                maxLeftBorderSum=leftBorderSum;
            }
        }
        for(int i=mid+1;i<=e;i++){
           rightBorderSum+=v[i];
           if(maxRightBorderSum<rightBorderSum){
                maxRightBorderSum=rightBorderSum;
            }
        }
        int crossBorderSum=maxLeftBorderSum+maxRightBorderSum;
        return max(maxLeftSum,max(maxRightSum,crossBorderSum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSumArrayHelper(nums,0,nums.size()-1);
    }
};