class Solution {
private:
    void solve(string digits,string output,vector <string>& ans,int index,string mapping[]){
        if(index>=digits.length()){
            if(output.length()>0){
            ans.push_back(output);
            }
            return;
        }
        int number = digits[index]-'0';
        string value=mapping [number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,output,ans,index+1,mapping);
            output.pop_back();      //backtracking removing of character mapped already
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector <string> ans;
        string output;
        int index=0;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno",  "pqrs","tuv","wxyz"};
        solve(digits,output,ans,index,mapping);
        return ans;
    }
};