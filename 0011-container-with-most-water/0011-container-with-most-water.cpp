class Solution {
public:
    int maxArea(vector<int>& arr) {
        int lPointer=0;
        int rPointer=arr.size()-1;
        int maxWater=0;
        while(lPointer<rPointer){
            maxWater=max(maxWater,(rPointer-lPointer)*min(arr[lPointer],arr[rPointer]));
            if(arr[lPointer]<arr[rPointer]){
                lPointer++;
            }
            else{
                rPointer--;
            }
        }
        return maxWater;
    }
};