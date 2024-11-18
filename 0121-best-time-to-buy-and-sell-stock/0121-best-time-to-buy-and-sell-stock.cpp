class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int todaysProfit=0;
        int maxProfit=INT_MIN;
        int minPriceToBuy=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minPriceToBuy){
                minPriceToBuy=prices[i];
            }
            todaysProfit=prices[i]-minPriceToBuy;
            if(todaysProfit>maxProfit){
                maxProfit=todaysProfit;
            }
        }
        return maxProfit;
    }
};