class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit=0;
        int minPrice=prices[0];
        int lastProfit=0;
        int prevElement=prices[0];
        int currElement=prices[0];
        for(int i=1;i<prices.size();i++){
            prevElement=currElement;
            currElement=prices[i];
            if(prevElement>currElement || minPrice>prices[i]){
                minPrice=prices[i];
                prevElement=minPrice;
                totalProfit=totalProfit+lastProfit;
                lastProfit=0;
            }
            int todaysProfit=prices[i]-minPrice;
            if(todaysProfit>lastProfit){
                lastProfit=todaysProfit;
            }
            
        }
        if(lastProfit>0){
            totalProfit=totalProfit+lastProfit;
        }
        return totalProfit;
    }
};