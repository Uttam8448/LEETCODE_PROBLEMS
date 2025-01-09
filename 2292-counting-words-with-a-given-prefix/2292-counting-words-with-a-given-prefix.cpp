class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        int j=0;
        int prefSize=pref.size();
        for(int i=0;i<words.size();i++){
            if(prefSize<=words[i].size()){
                j=0;
                count++;
                while(j<prefSize){
                    if(words[i][j]!=pref[j]){
                        count--;
                        break;
                    }
                    j++;
                }

            }
        }
        return count;
    }
};