class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int Sum=0;
        for(auto i: arr){
            Sum+=i;
        }
        int index=1;
        // Sum=Sum-arr[0];
        int leftSum=0;
        for(int i=0;i<arr.size();i++){
            if(i>0)
            leftSum+=arr[i-1];
            Sum=Sum-arr[i];
            if(leftSum==Sum){
                return i;
            }
        }
        return -1;
    }
};