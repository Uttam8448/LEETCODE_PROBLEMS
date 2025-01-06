class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size());
        int leftCount=0;
        int rightCount=0;
        int rightCost=0;
        int leftCost=0;
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                rightCount++;
                rightCost=rightCost+i;
            }
        }
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]=='0'){
                ans[i]=rightCost+leftCost;
                rightCost=rightCost-rightCount;
                leftCost=leftCost+leftCount;
            }
            else if(boxes[i]=='1'){
                ans[i]=rightCost+leftCost;
                rightCost=rightCost-rightCount;
                rightCount--;
                leftCount++;
                leftCost=leftCost+leftCount+1;
            }
        }
        return ans;
    }
};