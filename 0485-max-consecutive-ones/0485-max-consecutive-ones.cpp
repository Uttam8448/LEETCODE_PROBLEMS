class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        bool flag=false;
        int tempCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(!flag){
                    flag=true;
                    tempCount=1;
                    continue;
                }
                tempCount++;
            }
            if(nums[i]==0){
                flag=false;
                if(tempCount>count){
                    count=tempCount;
                }
                   
            }
        }
        if(tempCount>count) count=tempCount;
        return count;
    }
};