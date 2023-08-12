class Solution {
private:
    void solve(string digits,string output,vector <string>& ans,int index,vector<string>& mapping){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        int dig = digits[index]-'0';
        string value = mapping[dig];
        for(int i=0;i<value.length();i++){
            char ch = value[i];
            output.push_back(ch);
            solve(digits,output,ans,index+1,mapping);
            output.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector <string> ans;
        string output;
        int index=0;
        vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.length()==0){
            return ans;
        }
        solve(digits,output,ans,index,mapping);
        return ans;
    }
};