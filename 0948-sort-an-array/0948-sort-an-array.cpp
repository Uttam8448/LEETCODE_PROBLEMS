class Solution {
public:
void merge(vector<int>& nums,vector<int>& temp,int s,int mid,int e){
    int i=s,j=mid+1,k=s;
    while(i<=mid && j<=e){
        if(nums[i]<=nums[j])    temp[k++]=nums[i++];
        else    temp[k++]=nums[j++];
    }
    while(i<=mid)
        temp[k++]=nums[i++];
    while(j<=e)
        temp[k++]=nums[j++];
    for(;s<=e;s++){
        nums[s]=temp[s];
    }
}
    void mergeSort(vector<int>& nums,vector<int>& temp,int s,int e){
        if(s>=e)    return;
        int mid=(s+e)/2;
        mergeSort(nums,temp,s,mid);
        mergeSort(nums,temp,mid+1,e);
        merge(nums,temp,s,mid,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size(),0);
        mergeSort(nums,temp,0,nums.size()-1);
        return nums;
    }
};