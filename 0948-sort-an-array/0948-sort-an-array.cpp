class Solution {
public:
void merge(vector<int>& nums,int s,int mid,int e){
    int total_len=e-s+1;
    int gap=total_len/2+total_len%2;
    while(gap>0){
        int i=s;int j=gap+s;
        while(j<=e){
            if(nums[i]>nums[j]){
                swap(nums[i],nums[j]);
            }
            i++;
            j++;
        }
        gap= (gap <= 1) ? 0 : (gap /2)+(gap%2);
    }
}
    void mergeSort(vector<int>& nums,int s,int e){
        if(s>=e)    return;
        int mid=(s+e)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};