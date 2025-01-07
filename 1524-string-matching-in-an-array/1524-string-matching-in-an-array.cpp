class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int i=0;
        string temp;
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            temp=words[i];
            for(int j=0;j<words.size();j++){
                if(j!=i){
                    if(words[j].size()>temp.size() && words[j].find(temp)!=string::npos){
                        ans.push_back(temp);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};