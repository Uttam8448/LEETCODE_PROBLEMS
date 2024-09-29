class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        // map<int,int> mp;
        long long sum=0;
        sort(maximumHeight.begin(),maximumHeight.end());
        int maxCount=INT_MAX;
        for(int i=maximumHeight.size()-1;i>-1;i--){
            if(maxCount>maximumHeight[i]){
                maxCount=maximumHeight[i];
            }
            if(maxCount<=0){
                return -1;
            }
            sum=sum+maxCount;
            maxCount--;
        }
        return sum;
    }
};