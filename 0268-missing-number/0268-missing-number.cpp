class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            ans=ans+i;
            temp=temp+nums[i];
        }
        ans=ans+nums.size();
        return ans-temp;
    }
};