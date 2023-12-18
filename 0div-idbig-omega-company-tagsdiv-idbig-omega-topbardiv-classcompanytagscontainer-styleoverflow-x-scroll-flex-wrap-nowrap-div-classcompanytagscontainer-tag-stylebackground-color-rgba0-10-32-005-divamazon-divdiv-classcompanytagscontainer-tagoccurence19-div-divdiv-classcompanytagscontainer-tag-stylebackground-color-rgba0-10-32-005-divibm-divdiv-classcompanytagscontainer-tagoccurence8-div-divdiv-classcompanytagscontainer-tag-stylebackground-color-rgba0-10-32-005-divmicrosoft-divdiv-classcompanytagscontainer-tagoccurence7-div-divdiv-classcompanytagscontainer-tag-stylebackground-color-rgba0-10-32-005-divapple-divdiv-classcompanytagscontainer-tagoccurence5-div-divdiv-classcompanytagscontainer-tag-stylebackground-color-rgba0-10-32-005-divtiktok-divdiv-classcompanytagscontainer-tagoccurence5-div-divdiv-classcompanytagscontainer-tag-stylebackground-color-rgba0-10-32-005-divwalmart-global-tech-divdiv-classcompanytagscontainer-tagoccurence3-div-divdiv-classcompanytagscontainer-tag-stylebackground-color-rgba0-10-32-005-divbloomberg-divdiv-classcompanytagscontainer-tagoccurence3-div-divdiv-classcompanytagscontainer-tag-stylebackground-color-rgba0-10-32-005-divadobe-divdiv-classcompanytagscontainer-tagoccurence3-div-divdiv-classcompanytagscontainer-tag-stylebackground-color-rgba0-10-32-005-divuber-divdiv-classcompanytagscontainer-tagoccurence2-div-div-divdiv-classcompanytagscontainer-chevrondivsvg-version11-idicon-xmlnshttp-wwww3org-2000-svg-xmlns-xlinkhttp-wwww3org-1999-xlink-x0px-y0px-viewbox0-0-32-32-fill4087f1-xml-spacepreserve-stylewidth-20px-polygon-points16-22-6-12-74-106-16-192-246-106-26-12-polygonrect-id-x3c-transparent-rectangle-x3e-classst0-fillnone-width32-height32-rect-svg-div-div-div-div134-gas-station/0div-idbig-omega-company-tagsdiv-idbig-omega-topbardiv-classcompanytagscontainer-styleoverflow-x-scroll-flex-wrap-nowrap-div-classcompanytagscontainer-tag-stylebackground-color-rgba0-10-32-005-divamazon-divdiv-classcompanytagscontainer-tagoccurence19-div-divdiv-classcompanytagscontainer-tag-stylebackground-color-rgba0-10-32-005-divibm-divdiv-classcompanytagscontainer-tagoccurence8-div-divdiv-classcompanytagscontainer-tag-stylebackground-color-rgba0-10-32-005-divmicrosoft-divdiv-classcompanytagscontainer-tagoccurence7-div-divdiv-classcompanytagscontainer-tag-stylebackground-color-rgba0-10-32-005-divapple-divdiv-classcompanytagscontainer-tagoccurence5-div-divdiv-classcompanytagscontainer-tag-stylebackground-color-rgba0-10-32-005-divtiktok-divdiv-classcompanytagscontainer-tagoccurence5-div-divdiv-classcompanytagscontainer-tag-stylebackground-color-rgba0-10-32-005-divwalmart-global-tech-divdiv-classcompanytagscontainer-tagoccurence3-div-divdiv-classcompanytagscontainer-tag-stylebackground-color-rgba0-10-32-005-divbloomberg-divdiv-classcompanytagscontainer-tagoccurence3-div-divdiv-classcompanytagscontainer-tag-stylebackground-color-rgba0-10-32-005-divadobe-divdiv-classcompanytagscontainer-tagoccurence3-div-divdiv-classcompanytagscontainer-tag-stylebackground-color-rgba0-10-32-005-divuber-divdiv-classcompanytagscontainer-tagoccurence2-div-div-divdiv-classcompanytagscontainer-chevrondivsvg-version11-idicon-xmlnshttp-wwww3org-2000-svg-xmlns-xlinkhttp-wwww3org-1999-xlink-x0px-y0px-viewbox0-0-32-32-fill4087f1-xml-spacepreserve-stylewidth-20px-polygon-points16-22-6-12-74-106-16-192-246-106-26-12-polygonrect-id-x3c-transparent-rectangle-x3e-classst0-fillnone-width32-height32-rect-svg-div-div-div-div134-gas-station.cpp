class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //how much gas required
        int deficit = 0;
        //how much gas remains
        int balance = 0;
        //circuit starting from or return value;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            balance =balance +  gas[i] - cost[i];
            if(balance < 0){
                deficit+=balance;
                start=i+1;
                balance=0;
            }
        }
        if((deficit+balance)>=0){
            return start;
        }
        else{
            return -1;
        }
    }
};