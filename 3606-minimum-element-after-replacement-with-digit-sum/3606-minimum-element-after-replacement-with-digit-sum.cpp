class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            int sum=0;
            while(temp!=0){
                sum=sum+(temp%10);
                temp=temp/10;
            }
            arr.push_back(sum);
        }
        sort(arr.begin(),arr.end());
        return arr[0];
    }
};