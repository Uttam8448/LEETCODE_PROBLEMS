class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> preMax;
        vector<int> suffMax;
        int temp=0;
        int temp2=0;
        int j=height.size()-1;
        for(int i=0;i<height.size();i++){    
            temp=max(temp,height[i]);
            temp2=max(temp2,height[j]);
            preMax.push_back(temp);
            suffMax.insert(suffMax.begin(),temp2);
            j--;
        }
        int Water=0;
        for(int i=0;i<height.size();i++){
            Water=Water+min(preMax[i],suffMax[i])-height[i];
        }
        return Water;
    }
};