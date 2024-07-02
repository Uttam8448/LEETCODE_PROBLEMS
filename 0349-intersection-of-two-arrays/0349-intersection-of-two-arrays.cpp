class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nums1[i]);
                }
            }
        }
        if(ans.size()<1)    return ans;
        sort(ans.begin(),ans.end());
        vector<int> temp;
        
        temp.push_back(ans[0]);
        int prevElement=ans[0];
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1] || prevElement==ans[i]){
                continue;
            }
            temp.push_back(ans[i]);
            prevElement=ans[i];
        }
        if(prevElement!=ans[ans.size()-1]){
            temp.push_back(ans[ans.size()-1]);
        }
        return temp;
    }
};