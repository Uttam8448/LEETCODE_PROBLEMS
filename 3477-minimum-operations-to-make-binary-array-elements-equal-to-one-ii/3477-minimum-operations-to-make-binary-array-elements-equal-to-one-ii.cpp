class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ansCount=0;
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 && flag){
                ansCount++;                                              
                flag=false;
            }
            if(nums[i]==1 && flag){
                continue;
            }
            if(nums[i]==0 && !flag){
                // flag=true;
                // ansCount++;
                continue;
            }
            if(nums[i]==1 && !flag){
                ansCount++;
                flag=true;
            } 
        }
        return ansCount;
        
    }
};