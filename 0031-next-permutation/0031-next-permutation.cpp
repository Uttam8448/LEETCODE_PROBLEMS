class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // vector<int> ans;
        int max=INT_MIN;
        int index=-1;
        for(int i=nums.size()-1;i>-1;i--){
            if(nums[i]>max){
                max=nums[i];
            }
            if(nums[i]<max){
                index=i;
                break;
            }
        }
        if(index!=-1){
            int swapIndex=index;
            for(int i=nums.size()-1;i>index;i--){
                if(nums[i]>nums[index]){
                    swapIndex=i;
                    break;
                }
            }
            swap(nums[swapIndex],nums[index]);
            sort(nums.begin()+index+1,nums.end());
        }
        else{
            reverse(nums.begin(),nums.end());
        }
    }
};